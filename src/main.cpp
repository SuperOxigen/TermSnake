
#include <vector>
#include <string>
#include "tsbase.hpp"

using std::vector;
using std::string;

extern Status Main(vector<string> const &);

int main(int argc, char**argv)
{
    vector<string> args(argc);
    for (int32_t i = 0; i < argc; i++)
    {
        args.push_back(string(argv[i]));
    }

    Status ret = Main(args);

    return IS_OK(ret) ? 0 : 1;
}
