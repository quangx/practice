#include <iostream>

int main(){
/*	int count=0;
	while(1>0){
		int* a=new int[1]{3};
		std::cout<<std::to_string(++count)+" ";
	}
*/
	char c;
	char tracker;
	int index=0;
	char* c_array=new char[3000];
	while(c!='!'){
		std::cin>>c;
		
		c_array[index++]=c;
	}
	for(int i=0;i<index;i++){
		std::cout<<c_array[i];
	}
}
