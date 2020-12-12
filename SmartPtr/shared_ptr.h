template<typename T> 
class shared_pointer;

template<typename T>
shared_pointer<T> make_shared(T obj);

// This file implements a smart_pointer. This is an object that holds a pointer to 
// an object, but keeps track of how many other objects point to the same thing.
//
// There are two data members pointer, and counter. Pointer is obviously a pointer to
// the object inquestion. Note that counter is also a pointer, so that differenct objects
// can share access to the current number of things point to the object.
//
// Whenever a new object points to *pointer, *counter should increment. Whenever an 
// object that points to *pointer is destroyed either counter should decrease by 1, 
// or delete pointter and counter when *counter is <= 1 (i.e. the last thing pointing
// to *pointer deletes, last one out closes the door)
//
// This makes shart_pointer much safer to work with rather than working with raw pointers
// and having to remember to delete them.
//
// A note on constructors, you will need to implement the constructors, but I have created
// a helper function that calls the private constructor. This way there are only two options
// on how to create a smart pointer
//
//    shared_pointer<int> myptr1 = make_shared<int>(5); // creates smartpointer to value 5
//    shared_pointer<int> myptr2; // Initializes pointer and counter to nullptr
//
// This guarentees that there is no way we could forget to delete a pointer.
template <typename T>
class shared_pointer{
public:
	// friend functions can access private variables and methods
    friend shared_pointer<T> make_shared<T>(T obj); 

	// Default Constructor
    shared_pointer(): pointer{nullptr}, counter{nullptr}{
        // Initialize pointer to nullptr and counter to nullptr
	
    }

	// Copy Constructor
    shared_pointer(shared_pointer<T>& p): pointer{p.pointer}, counter{p.counter}{
        // New object created, increase counter by 1
	*counter=*counter+1;

    }
    
	// Move Constructor
    shared_pointer(shared_pointer<T>&& p): pointer{p.pointer}, counter{p.counter}{
	    p.pointer=nullptr;
	    p.counter=nullptr;
	    
    }
    
	// Copy Assignment
    shared_pointer<T>& operator=(shared_pointer<T>& p){
        // clear current values (make sure to decrement counter first)
        // Assign new values
        // increase  new counter
        // return *this
	*counter--;
	pointer=p.pointer;
	counter=p.counter;
	++*counter;
	return *this;
	
	

    }
    
	// Move Assignment
    shared_pointer<T>& operator=(shared_pointer<T>&& p){
        // clear current values (make sure to decrement counter)
        // Assign new values
        // increase  new counter (depending how you implement, may not need)
        // return *this;
	*counter--;
	pointer=p.pointer;
	counter=p.counter;
	*++counter;
	return *this;

    }
    
	// Destructor
    ~shared_pointer(){
        // If *counter > 1, decrease *counter
        // If *counter = 1, delete pointer and counter
        // Set pointer and counter to nullptr for safe delete of object;
	if(*counter>1){
		--*counter;
	}
	else if(*counter==1){
		pointer=nullptr;
		counter=nullptr;
	}
    }

    // Dereferencing    
    T& operator*() const {
        // return *pointer, make sure you don't dereference the nullptr
	if(pointer){
		return *pointer;
	}
    }
    
	// Reference Count
    int ref_count() const{ 
    	return *counter;
    }

private:
    T* pointer;
    int* counter;
   
    shared_pointer(T* p): pointer{p} ,counter{new int(0)}{
	    *counter=1;
    }
            
};


template<typename T>
shared_pointer<T> make_shared(T obj){
    return shared_pointer<T>(new T(obj));
};
