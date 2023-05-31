//
// Created by 93539 on 2023/5/25.
//

#ifndef VECTOR106_VECTOR_H
#define VECTOR106_VECTOR_H

namespace wyp {
    template<class T>
    class vector {
    public:
        typedef T *iterator;
        typedef const T *const_iterator;

        iterator begin() {
            return _start;
        }

        const_iterator begin() const {
            return _start;
        }

        iterator end() {
            return _finish;
        }

        const_iterator end() const {
            return _finish;
        }

        T &operator[](size_t pos) {
            assert(pos < size());
            return _start[pos];
        }

        const T &operator[](size_t pos) const {
            assert(pos < size());
            return _start[pos];
        }

        size_t size() const {
            return _finish - _start;
        }

        bool empty() const {
            return _start == _finish;
        }

        size_t capacity() const {
            return _end_of_storage - _start;
        }

        void reserve(size_t n) {
            if (n > capacity()) {
                size_t old_size = size();
                T *tmp = new T[n];
                if (_start) {
                    ////memcpy(tmp, _start, sizeof(T) * old_size);
                    for(int i = 0; i < old_size; ++i){
                        tmp[i] = _start[i];
                    }
                    delete[] _start;
                }
                _start = tmp;
                _finish = _start + old_size;
                _end_of_storage = _start + n;
            }
        }

        void resize(size_t n, T value = T()) {
            if (n > capacity()) {
                reserve(n);
            }
            if (n > size()) {
                while (_finish < _start + n) {
                    *(_finish++) = value;
                }
            } else {
                _finish = _start + n;
            }
        }

        template<class InputIterator>
        vector(InputIterator first, InputIterator last)
                : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {
            while (first != last) {
                push_back(*first);
                ++first;
            }
        }

        vector()
                : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {

        }

        vector(const vector<T> &v)
                : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {
            vector<T> tmp(v.begin(), v.end());
            swap(tmp);
        }

        vector<T>& operator=(vector<T> v){
            swap(v);
            return *this;
        }

        ~vector() {
            delete[] _start;
            _start = _finish = _end_of_storage = nullptr;
        }

        void push_back(const T &value) {
            if (_finish == _end_of_storage) {
                size_t newCapacity = capacity() == 0 ? 4 : 2 * capacity();
                reserve(newCapacity);
            }
            *(_finish++) = value;
        }

        void pop_back() {
            assert(!empty());
            --_finish;
        }

        iterator insert(iterator pos, const T &value) {
            assert(pos >= _start);
            assert(pos < _finish);
            if (size() == capacity()) {
                size_t len = pos - _start;
                size_t newCapacity = capacity() == 0 ? 4 : 2 * capacity();
                reserve(newCapacity);
                pos = _start + len;
            }
            iterator end = _finish - 1;
            while (end >= pos) {
                *(end + 1) = *end;
                --end;
            }
            *pos = value;
            ++_finish;
            return pos;
        }

        iterator erase(iterator pos) {
            assert(pos >= _start);
            assert(pos < _finish);
            iterator begin = pos + 1;
            while (begin < _finish) {
                *(begin - 1) = *begin;
                ++begin;
            }
            --_finish;
            return pos;
        }

        void swap(vector<T> &v) {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_end_of_storage, v._end_of_storage);
        }

        void clear() {
            _finish = _start;
        }

    private:
        iterator _start;
        iterator _finish;
        iterator _end_of_storage;
    };
}


#endif //VECTOR106_VECTOR_H
