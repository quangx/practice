#include <iostream>
#include "Link.h"



Link* Link::add(Link* n){
	Link* p=this;
	if(p==nullptr)
		return n;
	if(n==nullptr)
		return p;
	p->succ=n;
	n->prev=p;
}

Link* Link::insert(Link* j){
	Link* p=this;
	if(j==nullptr)
		return p;
	if(p==nullptr)
		return j;
	j->succ=p; 
	if(p->prev){
		p->prev->succ=j;
		j->prev=p->prev;
		p->prev=j;
		return j;
	}
}
Link* Link::advance(Link* p,int n) const{

	if(p==nullptr)
		return nullptr;
	if(0<n){
		while(n--){
			if(p->succ==nullptr) return nullptr;
			p=p->succ;
		}
	}
	else if(n<0){
		while(n++){
			if(p->prev==nullptr) return nullptr;
			p=p-> prev;
		}
	}
}
Link* Link::find(const std::string& s){
	Link* p=this;
	while(p){
		if(p->value==s) return p;
		p=p->succ;

	}
	return nullptr;
}
		
Link* Link::erase(){
	Link* p=this;
	if(p==nullptr){
		return nullptr;
	}
	if(p->succ)p->succ->prev=p->prev;
	if(p->prev)p->prev->succ=p->succ;
	return p->succ;
}

Link::~Link(){
	Link* p=this;
	while(p){
		track = p;
		p=p->next;
		delete[] track;
	}
}
