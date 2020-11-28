#include <iostream>
#include "shared_ptr.h"
// Below each line is shown what the current state should be, (var : *ptr : *counter)
//  
// I recommend commenting these out and adding them back  
// as the work one by one. 

int main(){
	// test move constructor:
	shared_pointer<int> ptr(make_shared<int>(9));
	 
	//(ptr : 9 : 1)

	// test copy constructor: 
	shared_pointer<int> ptr2 = ptr;
	
	//(ptr2 : 9 : 2), (ptr : 9 : 2)

	// test copy constructor 
	shared_pointer<int> ptr3(ptr2);
	
	//(ptr3 : 9 : 3), (ptr2 : 9 : 3), (ptr : 9 : 3)

	// test default constructor 
	shared_pointer<int> null;                                            

	//(null : NULL : NULL), (ptr3 : 9 : 3), (ptr2 : 9 : 3), (ptr : 9 : 3)	
	
	// test copy assignment 
	ptr3 = ptr;

	//(null : NULL : NULL), (ptr3 : 9 : 3), (ptr2 : 9 : 3), (ptr : 9 : 3)
	
	// test move assignment 
	ptr2 = make_shared<int>(3);

	//(null : NULL : NULL), (ptr3 : 9 : 2), (ptr2 : 3 : 1), (ptr : 9 : 2)

	// test copy assignment 
	null = ptr2;

	//(null : 3 : 2), (ptr3 : 9 : 2), (ptr2 : 3 : 2), (ptr : 9 : 2)

		
	std::cout << &(*ptr)  << " : " << *ptr  << " : " << ptr.ref_count()  << std::endl;
	std::cout << &(*ptr2) << " : " << *ptr2 << " : " << ptr2.ref_count() << std::endl;
	std::cout << &(*ptr3) << " : " << *ptr3 << " : " << ptr3.ref_count() << std::endl;
	std::cout << &(*null) << " : " << *null << " : " << null.ref_count() << std::endl;
}
