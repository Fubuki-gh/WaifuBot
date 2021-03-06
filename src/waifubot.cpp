#include <waifubot.hpp>

WaifuBot::WaifuBot(std::string token) : token(token)
{

}

WaifuBot::~WaifuBot()
{
    cluster_delete();
}

void WaifuBot::cluster_spawn(uint32_t num_clusters, uint32_t num_shards)
{
    dpp::cache_policy_t cache_policy;
    cache_policy.user_policy = dpp::cp_lazy;
    cache_policy.role_policy = dpp::cp_aggressive;
    cache_policy.emoji_policy = dpp::cp_aggressive;

    for (uint32_t i = 0; i < num_clusters; i++)
    {
        dpp::cluster* cluster = new dpp::cluster(token, dpp::i_default_intents, num_shards, i, num_clusters, true, cache_policy);

        cluster->set_websocket_protocol(dpp::websocket_protocol_t::ws_etf);

        register_events(cluster);

        clusters.push_back(cluster);
    }
}

void WaifuBot::cluster_start(bool return_after)
{
   for (auto cluster : clusters)
   {
       cluster->start(true);
   }
   while (!return_after)
   {
       std::this_thread::sleep_for(std::chrono::hours(10));
   }
   
}

void WaifuBot::cluster_delete()
{
    for (auto cluster : clusters)
    {
        delete cluster;
    }
}

void WaifuBot::register_events(dpp::cluster* cluster)
{
    cluster->on_log(dpp::utility::cout_logger());

    cluster->on_ready([this, cluster](const dpp::ready_t &event) {
        //Register slash commands once
        if (dpp::run_once<struct register_bot_commands>()) {
            register_commands(cluster);
        }
    });

    cluster->on_interaction_create([this, cluster](const dpp::interaction_create_t &event) {
        register_on_interactions(cluster, event);
    });

    cluster->on_button_click([this, cluster](const dpp::button_click_t &event) {
        register_on_button_click(cluster, event);
    });

    cluster->on_form_submit([this, cluster](const dpp::form_submit_t &event) {
        register_on_form_submit(cluster, event);
    });

}

