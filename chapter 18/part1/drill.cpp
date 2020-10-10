char* strdup(const char* c){
	int i=0;
	char* copy;
	while(c[i]!="\0"){
		copy[i]=c[i];
		i++;
	}
	copy[i]="\0";
}

