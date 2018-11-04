/*
 *  Terminal Handler
 */

#pragma once

#include <memory>
#include <string>

#include <termios.h>

#include "tsbase.hpp"

namespace ts {

enum class TermColor {
    NONE,
    DEFAULT,
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    LIGHT_GRAY,
    DARK_GRAY,
    LIGHT_RED,
    LIGHT_GREEN,
    LIGHT_YELLOW,
    LIGHT_BLUE,
    LIGHT_MAGENTA,
    LIGHT_CYAN,
    WHITE
};

enum class TermMood {
    NONE,
    BOLD,
    DIM,
    UNDERLINED,
    BLINKING
};

class Term {
    fd_t _fd;

    /* Term Resolution */
    uint32_t _width;
    uint32_t _height;

    uint32_t _cur_row;
    uint32_t _cur_col;

    /* Output State */
    TermColor _forground_color;
    TermColor _background_color;
    TermMood _text_mood;

    bool_t _term_set;
    struct termios _original_term_state;

    Term();
    bool_t Init(fd_t);

    bool_t InitTerminalState(void);
    bool_t RestoreTerminalState(void);

    bool_t DetermineTermSize(void);

    fd_t GetFd(void) const;

    void Print(char_t const * buf);
public:
    ~Term();
    static ::std::shared_ptr<Term> Create(fd_t term_fd);

    /* Prevent Copying */
    Term(const Term&) = delete;
    Term& operator=(const Term&) = delete;

    /* Resolution State */
    uint32_t GetWidth(void) const;
    uint32_t GetHeight(void) const;
    void Resize(void);

    /* Cursor Position */
    uint32_t GetCursorRow(void) const;
    uint32_t GetCursorCol(void) const;

    void SetCursorRow(uint32_t row);
    void SetCursorCol(uint32_t col);

    void MoveCursorLeft(int32_t dis);
    void MoveCursorRight(int32_t dis);
    void MoveCursorUp(int32_t dis);
    void MoveCursorDown(int32_t dis);

    /* Printers */
    void PutChar(char_t c);
    void PutString(::std::string const & s);
    void ClearTerm(void);

    /* Term Colors and Mood */
    TermColor GetForgroundColor(void) const;
    TermColor GetBackgroundColor(void) const;
    TermMood GetTextMood(void) const;

    void SetForgroundColor(TermColor color);
    void SetBackgroundColor(TermColor color);
    void SetTextMood(TermMood mood);

    void ClearColors(void);
    void ClearMood(void);
    void ClearTextFormatters(void);
};

using TermPtr = ::std::shared_ptr<Term>;

} /* Namespace ts */
