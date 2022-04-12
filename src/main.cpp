#include <waifubot.hpp>
#include <chrono>

int main()
{
    WaifuBot bot("Nzg4NDY4MTUxMjAwNTE0MDg4.X9j8MA.rISiYfqxwzJTwU9XtAWQ1IR7eJw");

    bot.cluster_spawn(1, 1);
    bot.cluster_start();

    while(true) {
        //wait 5 hours
        std::this_thread::sleep_for(std::chrono::hours(5));
    }

    return 0;
}