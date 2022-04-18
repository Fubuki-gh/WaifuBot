#include <waifubot.hpp>
#include <commands.hpp>

void Command::on_interaction_create(dpp::cluster* cluster, const dpp::interaction_create_t& event) {
    event.reply("unimplemented");
}

void Command::on_button_click(dpp::cluster* cluster, const dpp::button_click_t& event) {
    event.reply("unimplemented");
}

void Command::on_form_submit(dpp::cluster* cluster, const dpp::form_submit_t& event) {
    event.reply("unimplemented");
}

void Command::on_select_click(dpp::cluster* cluster, const dpp::select_click_t& event) {
    event.reply("unimplemented");
}

void WaifuBot::register_commands(dpp::cluster* cluster) {


    std::vector<dpp::slashcommand> commands = {
        dpp::slashcommand("about", "Infos about the bot", cluster->me.id)
    };

    cluster->global_bulk_command_create(commands);
}

void WaifuBot::register_on_interactions(dpp::cluster* cluster, const dpp::interaction_create_t& event) {
    
    AboutCommand about_command;

    if (event.command.get_command_name() == "about") {

        about_command.on_interaction_create(cluster, event);
    }
}

void WaifuBot::register_on_button_click(dpp::cluster* cluster, const dpp::button_click_t& event) {
    
    AboutCommand about_command;

    if (event.custom_id.starts_with("about_")) {

        about_command.on_button_click(cluster, event);   
    }
}

void WaifuBot::register_on_select_click(dpp::cluster* cluster, const dpp::select_click_t& event) {
    return;
}

void WaifuBot::register_on_form_submit(dpp::cluster* cluster, const dpp::form_submit_t& event) {
    
    AboutCommand about_command;

    if (event.custom_id == "feedback_modal") {
        about_command.on_form_submit(cluster, event);
    }

}
