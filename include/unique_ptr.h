#ifndef UNIQUE_PTR
#define UNIQUE_PTR

template <typename T>
class UniquePtr 
{
    public :
        UniquePtr(T *ptr);
        UniquePtr();
        template <typename U>
        friend U* make_unique(U value);
        ~UniquePtr();
        UniquePtr(UniquePtr& ptr);
        UniquePtr &operator=(UniquePtr& ptr);
        T* get();
        T operator*();
        T* operator->();
        void reset();
        void reset(T* newPtr);
        T *release();
        explicit operator bool() const;

    private:
        T* _p;
};

#include "unique_ptr.hpp"

#endif //UNIQUE_PTR