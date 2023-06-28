//
// Created by 93539 on 2023/6/28.
//

#ifndef VECTOR106_REVERSER_ITERATOR_H
#define VECTOR106_REVERSER_ITERATOR_H

namespace wyp {
    template<class Iterator, class Ref, class Ptr>
    class _reverser_iterator {
        typedef _reverser_iterator<Iterator, Ref, Ptr> Self;
    public:
        _reverser_iterator(Iterator it)
                : _it(it) {

        }

        Self &operator++() {
            --_it;
            return *this;
        }

        Self &operator--() {
            ++_it;
            return *this;
        }

        Ref operator*(){
            Iterator tmp = _it;
            return *(--tmp);
        }

        Ptr operator&(){
            return &(operator*());
        }

        bool operator!=(const Self& s) const{
            return _it != s._it;
        }

    private:
        Iterator _it;
    };

} // wyp

#endif //VECTOR106_REVERSER_ITERATOR_H
