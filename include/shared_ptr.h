#ifndef SHARED_PTR
#define SHARED_PTR

#include <map>
#include <vector>

using std::map;
template <typename T>
class SharedPtr
{
    public :
        SharedPtr(T *ptr);
        SharedPtr();
        template <typename U>
        friend U *make_shared(U value);
        ~SharedPtr();
        SharedPtr(SharedPtr &ptr);
        SharedPtr &operator=(SharedPtr &ptr);
        T *get();
        T operator*();
        T operator->();
        void reset();
        void reset(T *newPtr);
        T *release();

    private:
        T *_p;
        static map<T *, int> PointerToCountMap = {};
};

#include "shared_ptr.hpp"

#endif //SHARED_PTR