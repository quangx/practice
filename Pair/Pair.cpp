#include <iostream>
#include <vector>
#include <string>
template <typename T,typename U> 
class S{
public:	S(T t, U u){
		t1=t;
		u1=u;
	}
	void say(){
		std::cout<<t1+" "+std::to_string(u1)<<std::endl;
	}
private:
	T t1;
	U u1;

};
int main(){
	S<std::string,double> object ("string", 17.63);
	object.say();


}
