#include <iostream>
class Link {
	public:
		std::string value;
		Link(const std::string& v, Link* p = nullptr, Link* s = nullptr): value{v}, prev{p}, succ{s} { }	
		Link* insert(Link* n) ;
		Link* add(Link* n) ;
		Link* erase();
		Link* find(const std::string& s);
		Link* advance(Link* p,int n) const; 
		Link* next() const { 
			return succ; 
		}
		Link* previous() const { 
			return prev; 
		}


	private:
		Link* prev;
		Link* succ;
};
