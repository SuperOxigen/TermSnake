
#include <unistd.h>

#include <vector>
#include <string>
#include "tsbase.hpp"
#include "term.hpp"

using std::vector;
using std::string;

using std::string;
using ts::Term;

Status Main(vector<string> const & args) {
    auto term = Term::Create(STDOUT_FILENO);

    uint32_t n = 0;
    for (uint32_t r = 0; r < term->GetHeight(); r++) {
        for (uint32_t c = 0; c < term->GetWidth(); c++) {
            char ch = ' ';
            if ((n % 5) == 0) {
                ch = 'A';
            } else if ((n % 7) == 0) {
                ch = 'B';
            } else if ((n % 11) == 0) {
                ch = 'C';
            } else if ((n % 13) == 0) {
                ch = 'D';
            } else if ((n % 17) == 0) {
                ch = 'E';
            }
            term->PutChar(ch);
            n++;
        }
    }

    return Status::Ok;
}
