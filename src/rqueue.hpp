#pragma once

#include "tsbase.hpp"

namespace ts {

template <typename T>
class RingQueue {
    static uint32_t constexpr DEFAULT_LINEAR_RESIZE = 256;

    T * _buffer;
    uint32_t _buf_size;

    uint32_t _front;
    uint32_t _back;
    uint32_t _size;

    uint32_t _linear_resize;

    void pushFront(void);
    void pushBack(void);

    bool_t shouldDownSize(void) const;
    bool_t shouldUpSize(void) const;

    void upSize(void);
    void downSize(void);

public:
    RingQueue(void);

    uint32_t Size(void) const;
    bool_t PushElement(T elem);
    bool_t PopElement(T * elem);
};


template<typename T>
RingQueue<T>::RingQueue(void):
        _buffer(nullptr),
        _buf_size(0),
        _front(0),
        _back(0),
        _linear_resize(DEFAULT_LINEAR_RESIZE) {
    if (DEFAULT_LINEAR_RESIZE > 0) {
        _buffer = new T[2*DEFAULT_LINEAR_RESIZE];
        if (_buffer) {
            _buf_size = 2*DEFAULT_LINEAR_RESIZE;
        }
    }
}

template<typename T>
uint32_t RingQueue<T>::Size(void) const {
    return _size;
}

template<typename T>
bool_t RingQueue<T>::PushElement(T elem) {

    if (shouldUpSize()) {
        upSize();
    }

}

template<typename T>
bool_t RingQueue<T>::PopElement(T * elem) {
    if (Size() == 0) {
        return false;
    }



    if (shouldDownSize()) {
        downSize();
    }
}

/* private methods */
template<typename T>
void RingQueue<T>::pushFront(void) {
    if (_size == 0) return;
    _front++;
    _size--;
    if (_front == _buf_size) {
        _front = 0;
    }
}

template<typename T>
void RingQueue<T>::pushBack(void) {
    if (_size == _buf_size) return;
    _back++;
    _size++;
    if (_back == _buf_size) {
        _back = 0;
    }
}

template<typename T>
bool_t RingQueue<T>::shouldDownSize(void) const {
    if (_buf_size <= (2*_linear_resize)) {
        return false;
    }

    if ((_buf_size - (2*_linear_resize)) > _size) {
        return true;
    }

    return false;
}

template<typename T>
bool_t RingQueue<T>::shouldUpSize(void) const {
    if ((_buf_size - _linear_resize) <= _size) {
        return true;
    }
    return false;
}

template<typename T>
void RingQueue<T>::upSize(void) {
    T * new_array = new T[_buf_size + _linear_resize];
}

};  /* namespace */
