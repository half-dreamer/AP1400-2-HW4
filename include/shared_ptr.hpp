//static class member can't be defined and initialized in class declaration
template <typename T>
map<T *, int> SharedPtr<T>::PointerToCountMap = {};

template <typename T>
SharedPtr<T>::SharedPtr()
{
    _p = nullptr;
}


template <typename T>
SharedPtr<T>::SharedPtr(T *ptr) 
{
    _p = ptr;
    // in this case, you don't have to check for 
    // whether ptr exists in map, because operator[] 
    // will create one with initial value 0 for you
    PointerToCountMap[ptr]++;
}

template <typename T>
SharedPtr<T>::~SharedPtr() 
{
    // ! well ,I don't know what will happen if I delete this if statement
    PointerToCountMap[_p] --;
    if (PointerToCountMap[_p] == 0)
    {
        delete (_p);
    }
    _p = nullptr;
}

template <typename U>
U* make_shared(U value) 
{
    U *newPtr = new U(value);
    return newPtr;
}

template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr& ptr)
{
    _p = ptr.get();
    PointerToCountMap[_p]++;
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr& ptr) 
{
    PointerToCountMap[_p]--;
    _p = ptr.get();
    PointerToCountMap[_p]++;
    return ptr;
}

template <typename T>
T* SharedPtr<T>::get() 
{
    return _p;
}

template <typename T>
T SharedPtr<T>::operator*() 
{
    return *(_p);
}

template <typename T>
T* SharedPtr<T>::operator->() 
{
    return _p;
}

template <typename T>
int SharedPtr<T>::use_count()
{
    if (_p == nullptr) {
        return 0;
    }
    return PointerToCountMap[_p];
}

template <typename T>
void SharedPtr<T>::reset() 
{
    PointerToCountMap[_p] = 0;
    delete (_p);
    _p = nullptr;
}

template <typename T>
void SharedPtr<T>::reset(T* ptr) 
{
    PointerToCountMap[_p] = 0;
    delete (_p);
    _p = ptr;
    PointerToCountMap[_p]++;
}

template <typename T>
SharedPtr<T>::operator bool() const
{
    return _p;
}