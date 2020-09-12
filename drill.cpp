#include <iostream>
#include <vector>
void print_array10(std::ostream& os,int* a){
        for(int i = 0 ;i < 10;i++){
                os<<std::to_string(a[i])+" ";
        }
	os<<std::endl;
}
void print_array(std::ostream& os, int* a,int n){
	for(int i=0;i<n;i++){
		os<<std::to_string(a[i])+ " ";
	}
	os<<std::endl;
}
void print_vector(std::ostream& os, const std::vector<int> &v){
	
}
void print_vector10(std::ostream& os,const std::vector<int> &v){
	for(int i=0;i<10;i++){
		os<<std::to_string(v[i])+" ";
	}
	os<<std::endl;
}
int main(){
	int* v=new int[10]{1,2,3,4,5,6,7,8,9,10};
	delete[] v;
	int *t=new int [10]{101,102,103,104,105,106,107,108,109,110};
	print_array10(std::cout,t);
	delete[] t;
	int *u=new int[11]{11,12,13,14,15,16,17,18,19,20,21};
	print_array10(std::cout,u);
	delete[] u;
	std::vector<int> t2(10);
	for(int i = 0 ; i< 10; i++){
		t2[i]=100+i;
	}
	std::vector<int> u2(10);
	for(int i=0;i<11;i++){
		u2[i]=100+i;
	}
	print_vector10(std::cout,t2);
	print_vector10(std::cout,u2);
}

