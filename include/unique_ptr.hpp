template <typename T>
UniquePtr<T>::UniquePtr()
{
    _p = nullptr;
}


template <typename T>
UniquePtr<T>::UniquePtr(T *ptr) 
{
    _p = ptr;
}

template <typename T>
UniquePtr<T>::~UniquePtr() 
{
    // ! if _p == nullptr, nothing should be done
    delete (_p);
    _p = nullptr;
}

template <typename U>
U* make_unique(U value) 
{
    return new U(value);
}

template <typename T>
UniquePtr<T>::UniquePtr(UniquePtr& ptr)
{
    static_assert(true, "can't copy a UniquePtr!");
}

template <typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr& ptr) 
{
    _p = ptr.get();
}

template <typename T>
T* UniquePtr<T>::get() 
{
    return _p;
}

template <typename T>
T UniquePtr<T>::operator*() 
{
    return *(_p);
}

template <typename T>
T* UniquePtr<T>::operator->() 
{
    return _p;
}

template <typename T>
void UniquePtr<T>::reset() 
{
    delete (_p);
    _p = nullptr;
}

template <typename T>
void UniquePtr<T>::reset(T* ptr) 
{
    delete (_p);
    _p = ptr;
}

template <typename T>
T* UniquePtr<T>::release() 
{
    T* releasedPtr = _p;
    _p = nullptr;
    return releasedPtr;
}

template <typename T>
UniquePtr<T>::operator bool() const
{
    return _p;
}