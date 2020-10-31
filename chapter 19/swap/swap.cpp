#include <iostream>

void swap(int* a[], int* b[]){
	int* t=*a;
	*a=*b;
	*b=t;
}
int main(){
	int* a=new int[4]{1,2,3,4};
	int* b=new int[4]{5,6,7,8};
	swap(&a,&b);
	for(int i=0;i<4;i++){
		std::cout<<std::to_string(a[i])+" ";
	}
	std::cout<<std::endl;
	for(int i=0;i<4;i++){
		std::cout<<std::to_string(b[i])+" ";
	}
	std::cout<<std::endl;
}
