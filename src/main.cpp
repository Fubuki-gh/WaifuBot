#include <waifubot.hpp>

std::string get_token(std::string filename)
{
    std::ifstream token_file(filename);
    std::string token;
    token_file >> token;
    return token;
}

int main(int argc, char* argv[])
{

    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <token_file>" << std::endl;
        return 1;
    }

    WaifuBot bot(get_token(argv[1]));

    bot.cluster_spawn(1, 1);
    bot.cluster_start(false);

    return 0;
}