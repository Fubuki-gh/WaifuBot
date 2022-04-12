#include <waifubot.hpp>
#include <chrono>

int main()
{
    WaifuBot bot("token");

    bot.cluster_spawn(1, 1);
    bot.cluster_start();

    while(true) {
        //wait 5 hours
        std::this_thread::sleep_for(std::chrono::hours(5));
    }

    return 0;
}