#ifndef SMARTPTR_H
#define SMARTPTR_H
#include "IRefCountImpl.h"


template <class T> class SmartPtr
{

private:
    IRefCount<T> *m_refcount;

    /////////////////////////////////////////
    // __RefCounter
    // An internal implementation of IRefCount
    // for classes that don't implement it
    // SmartPtr will automatically choose between its internal and
    // class' implementation of IRefCount
    class __RefCounter : public IRefCountImpl<T>
    {
        private:
        T *__m_ptr;
        protected:
        virtual T * GetPtr() const
        {
            return __m_ptr;
        }
        virtual void __DestroyRef() {delete this;}
        public:

        __RefCounter(T *ptr)
        {
            __m_ptr = ptr;
        }
        virtual ~__RefCounter()
        {
            IRefCountImpl<T>::__DestroyRef();
        }
    };
    // this method is called if T does not implement IRefCount
    void Assign(void *ptr)
    {
        if(ptr==NULL)
            Assign((IRefCount<T> *)NULL);
        else
        {
            Assign(new __RefCounter(static_cast<T *>(ptr)));
        }
    }
    // this method is picked over Assign(void *ptr)
    // if T implements IRefCount.
    // This allows some memory usage optimization
    void Assign(IRefCount<T> *refcount)
    {
        if(refcount!=NULL)
            refcount->__IncRefCount();

        IRefCount<T> *oldref = m_refcount;
        m_refcount = refcount;

        if(oldref!=NULL)
            oldref->__DecRefCount();
    }

public:
    SmartPtr()
    {
        m_refcount = NULL;
    }
    SmartPtr(T * ptr)
    {
        m_refcount = NULL;

        Assign(ptr);
    }
    SmartPtr(const SmartPtr &sp)
    {
        m_refcount = NULL;
        Assign(sp.m_refcount);
    }
    virtual ~SmartPtr()
    {
        Assign((IRefCount<T> *)NULL);
    }

    // get the contained pointer, not really needed but...
    T *GetPtr() const
    {
        if(m_refcount==NULL) return NULL;
            return m_refcount->GetPtr();
    }

    // assign another smart pointer
    SmartPtr & operator = (const SmartPtr &sp) {Assign(sp.m_refcount); return *this;}
    // assign pointer or NULL
    SmartPtr & operator = (T * ptr) {Assign(ptr); return *this;}
    // to access members of T
    T * operator ->()
    {
        if (GetPtr()!=NULL)
            return GetPtr();
    }
    // conversion to T* (for function calls)
    operator T* () const
    {
        return GetPtr();
    }

    // utilities
    bool operator !()
    {
        return GetPtr() == NULL;
    }
    bool operator ==(const SmartPtr &sp)
    {
        return GetPtr()==sp.GetPtr();
    }
    bool operator !=(const SmartPtr &sp)
    {
        return GetPtr()!=sp.GetPtr();
    }
};

#endif // SMARTPTR_H
