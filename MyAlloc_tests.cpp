#include <iostream>
#include <vector>

#include <limits>
#include <iostream>

namespace MyLib {
   template <class T>
   class MyAlloc {
     public:
       // type definitions
       typedef T        value_type;
       typedef T*       pointer;
       typedef const T* const_pointer;
       typedef T&       reference;
       typedef const T& const_reference;
       typedef std::size_t    size_type;
       typedef std::ptrdiff_t difference_type;

       // rebind allocator to type U
       template <class U>
       struct rebind {
           typedef MyAlloc<U> other;
       };

       // return address of values
       pointer address (reference value) const {
           return &value;
       }
       const_pointer address (const_reference value) const {
           return &value;
       }

       /* constructors and destructor
        * - nothing to do because the allocator has no state
        */
       MyAlloc() throw() {
       }
       MyAlloc(const MyAlloc&) throw() {
       }
       template <class U>
         MyAlloc (const MyAlloc<U>&) throw() {
       }
       ~MyAlloc() throw() {
       }

       // return maximum number of elements that can be allocated
       size_type max_size () const throw() {
           return std::numeric_limits<std::size_t>::max() / sizeof(T);
       }

       // allocate but don't initialize num elements of type T
       pointer allocate (size_type num, const void* = 0) {
           // print message and allocate memory with global new
           std::cerr << "allocate " << num << " element(s)"
                     << " of size " << sizeof(T) << std::endl;
           //try {
             pointer ret = (pointer)(::operator new(num*sizeof(T)));
             std::cerr << " allocated at: " << (void*)ret << std::endl;
             return ret;
           //}
           //catch (...)
           //{
           // std::cerr << "CATCH!" << std::endl;
           //}
           return pointer{};
       }

       // initialize elements of allocated storage p with value value
       void construct (pointer p, const T& value) {
           // initialize memory with placement new
           new((void*)p)T(value);
       }

       // destroy elements of initialized storage p
       void destroy (pointer p) {
           // destroy objects by calling their destructor
           p->~T();
       }

       // deallocate storage p of deleted elements
       void deallocate (pointer p, size_type num) {
           // print message and deallocate memory with global delete
           std::cerr << "deallocate " << num << " element(s)"
                     << " of size " << sizeof(T)
                     << " at: " << (void*)p << std::endl;
           ::operator delete((void*)p);
       }
   };

   // return that all specializations of this allocator are interchangeable
   template <class T1, class T2>
   bool operator== (const MyAlloc<T1>&,
                    const MyAlloc<T2>&) throw() {
       return true;
   }
   template <class T1, class T2>
   bool operator!= (const MyAlloc<T1>&,
                    const MyAlloc<T2>&) throw() {
       return false;
   }
}

class classA 
{
public:
classA () { std::cout << "classA ()" << std::endl; }
~classA () { std::cout << "~classA ()" << std::endl; }
};

int main ()
{
  classA a;
  std::vector<std::vector<int, MyLib::MyAlloc<int>>> v;
  constexpr int size1 = 10000;
  constexpr int size2 = 100000000;
  v.reserve (size1);
  try
    {
      for (int i = 1; i <= size1; ++i)
        {
          v.push_back (std::vector<int, MyLib::MyAlloc<int>> (size2));
          std::cout << i << std::endl;
        }
    }
  catch(const std::runtime_error& re)
    {
        // speciffic handling for runtime_error
        std::cerr << "Runtime error: " << re.what() << std::endl;
        return 0;
    }
  catch(const std::exception& ex)
    {
        // speciffic handling for all exceptions extending std::exception, except
        // std::runtime_error which is handled explicitly
        std::cerr << "Error occurred: " << ex.what() << std::endl;
        return 0;
    }
  catch(...)
    {
        // catch any other errors (that we have no information about)
        std::cerr << "Unknown failure occurred. Possible memory corruption" << std::endl;
        return 0;
    }
  std::cout << std::endl << "OK, end." << std::endl;
}
