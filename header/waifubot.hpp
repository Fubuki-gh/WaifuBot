#pragma once
#include <dpp/dpp.h>
#include <dpp/fmt/format.h>

#include <vector>
#include <string>
#include <chrono>

#define BOT_VERSION_TEXT "0.1.0"
#define LIBRARY_VERSION_TEXT DPP_VERSION_TEXT
#define EMBED_COLOR 0x780674
#define EMBED_COLOR_ERROR 0xFF0000
#define EMBED_COLOR_DEV 0x00FF00

class WaifuBot
{
public:
    WaifuBot(std::string token);
    ~WaifuBot();

    void cluster_spawn(uint32_t num_clusters, uint32_t num_shards);
    void cluster_start(bool return_after = true);
    void cluster_delete();

private:
    std::string token;
    std::vector<dpp::cluster*> clusters;
    void register_events(dpp::cluster* cluster);
    void register_commands(dpp::cluster* cluster);
    void register_on_interactions(dpp::cluster* cluster, const dpp::interaction_create_t& event);
    void register_on_button_click(dpp::cluster* cluster, const dpp::button_click_t& event);
    void register_on_select_click(dpp::cluster* cluster, const dpp::select_click_t& event);
    void register_on_form_submit(dpp::cluster* cluster, const dpp::form_submit_t& event);

};