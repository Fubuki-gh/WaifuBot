#pragma once
#include <dpp/dpp.h>
#include <dpp/fmt/format.h>

#include <commands.hpp>

#include <vector>
#include <string>

class WaifuBot
{
public:
    WaifuBot(std::string token);
    ~WaifuBot();

    void cluster_spawn(uint32_t num_clusters, uint32_t num_shards);
    void cluster_start();
    void cluster_delete();

private:
    std::string token;
    std::vector<dpp::cluster*> clusters;
    void register_events(dpp::cluster* cluster);

};