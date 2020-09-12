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
	for(int i =0;i<v.size();i++){
		os<<std::to_string(v[i])+" ";
	}
	os<<std::endl;
}
void print_vector10(std::ostream& os,const std::vector<int> &v){
	for(int i=0;i<10;i++){
		os<<std::to_string(v[i])+" ";
	}
	os<<std::endl;
}
int main(){/*
	int* v=new int[10]{1,2,3,4,5,6,7,8,9,10};
	delete[] v;
	int *t=new int [10]{101,102,103,104,105,106,107,108,109,110};
	delete[] t;
	int *u=new int[11]{11,12,13,14,15,16,17,18,19,20,21};
	delete[] u;
	std::vector<int> t2(10);
	for(int i = 0 ; i< 10; i++){
		t2[i]=100+i;
	}
	std::vector<int> u2(10);
	for(int i=0;i<10;i++){
		u2[i]=100+i;
	}
	std::vector<int> new_u(15);
	for(int i=0;i<new_u.size();i++){
		new_u[i]=i+2;
	}
	print_vector(std::cout,new_u);
					*/
	
	int x=7;
	int* p1=&x;
	std::cout<<p1<<std::endl;
	std::cout<<*p1<<std::endl;
	int arr[7]{1,2,4,8,16,32,64};
	int* p2=arr;
	std::cout<<p2<<std::endl;
	for(int i=0;i<7;i++){
		std::cout<<std::to_string(p2[i])+" ";
	}
	std::cout<<"\n";
	int* p3=p2;
	p1=p2;
	std::cout<<p1<<std::endl;
	for(int i=0;i<7;i++){
		std::cout<<std::to_string(p1[i])+" ";
	}
	std::cout<<"\n";
	std::cout<<p2<<std::endl;
	for(int i=0;i<7;i++){
		std::cout<<std::to_string(p2[i])+" ";
	}
	std::cout<<"\n";
	delete[] p2;
}

