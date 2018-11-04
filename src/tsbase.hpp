
#pragma once

#include <cstdint>

using bool_t = bool;

enum class Status {
    Ok,
    Failure,
    Error
};

using fd_t = int32_t;

using bool_t = bool;
using char_t = char;

#define IS_OK(status) (::Status::Ok == (status))
