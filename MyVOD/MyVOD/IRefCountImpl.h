#ifndef IREFCOUNTIMPL_H
#define IREFCOUNTIMPL_H
#include "IRefCount.h"
#include <iostream>          //std::cout

using namespace std;


// IRefCountImpl
// is a standard implementation of IRefCount
// To use it just derive your class from it:
// class CMyObject : public IRefCountImpl<CMyObject> { ... };
// Reminder: implementing IRefCount is optional but it would reduce
// memory fragmentation.
template <class T> class IRefCountImpl : public IRefCount<T>
{
    private:
    int __m_counter;
    void prntCntr () {cout<<__m_counter<<"\n";}

    protected:
        virtual void __IncRefCount()
        {
            __m_counter++;
            cout<<"increased reference, it is now : ";
            prntCntr();
        }
        virtual void __DecRefCount()
        {
            __m_counter--;

            cout<<"Decreased reference, it is now : ";
            prntCntr();

            if(__m_counter<=0)
            {
                cout<<"Reference is 0, destroying Ref.\n";
                __DestroyRef();
            }
        }
        virtual T * GetPtr() const
        {
            return ((T *)this);
        }
        virtual void __DestroyRef()
        {
            if(GetPtr()!=NULL)
                delete GetPtr();
            cout<<"Deleted reference\n";
        }
        IRefCountImpl()
        {
            __m_counter = 0;
        }

};
#endif // IREFCOUNTIMPL_H
