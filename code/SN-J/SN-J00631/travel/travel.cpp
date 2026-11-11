//Gao YiFan 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	//freeopen("travel.in",r,w);
	//freeopen("travel.out",r,p);
	int c1,c2;
	string s1[3],s2[3];
	cin>>c1>>c2;
	for(int i=1;i<=3;i++){
		cin>>s1[i]>>s2[i];
	}
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}/*
	for(int i=1;i<=3;i++){
		if(s1[1]==s2[1]){
			if(s1[2]==s2[2]){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
	}
	*/
	return 0;
}
