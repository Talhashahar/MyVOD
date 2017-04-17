#ifndef IREFCOUNT_H
#define IREFCOUNT_H


template <class T> class IRefCount
 {

    template <class U> friend class SmartPtr;
    protected:
        virtual void __IncRefCount() = 0;
        virtual void __DecRefCount() = 0;
        virtual T * GetPtr() const = 0;
};

#endif // IREFCOUNT_H
