#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1.substr(0,2)!=s2.substr(0,2)){
		cout<<1000;
		return 0;
	}
	char a=s1[2];
	//在不在同一侧 
	if(a=='A'||a=='B'||a=='C'){
		if(s2[2]=='D'||s2[2]=='F'){
			cout<<1100;
			return 0;
		}
	}
	if(a=='D'||a=='F'){
		if(a=='A'||a=='B'||a=='C'){
			cout<<1100;
			return 0;
		}
	}
	//挨不挨着 
	if(a=='A'){
		if(s2[2]=='B'){
			cout<<1111;
		}else{
			cout<<1110;
		}
		return 0;
	}
	if(a=='B'){
		if(s2[2]=='A'||s2[2]=='C'){
			cout<<1111;
		}else{
			cout<<1110;
		}
		return 0;
	}
	if(a=='C'){
		if(s2[2]=='B'){
			cout<<1111;
		}else{
			cout<<1110;
		}
		return 0;
	}
	if(a=='D'){
		if(s2[2]=='F'){
			cout<<1111;
		}else{
			cout<<1110;
		}
		return 0;
	}
	if(a=='F'){
		if(s2[2]=='D'){
			cout<<1111;
		}else{
			cout<<1110;
		}
	}
	return 0;
}
