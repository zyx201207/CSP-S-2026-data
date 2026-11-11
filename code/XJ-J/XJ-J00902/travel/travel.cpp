#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	//处理一下字符串
	if(c1==c2){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	if(s1[2]=='D'&&s2[2]=='F'||s2[2]=='D'&&s1[2]=='F'){
		cout<<'1';
	}
	else if(s1[2]=='C'&&s2[2]=='D'||s2[2]=='C'&&s1[2]=='D'){
		cout<<'0';
	}
	else if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
		cout<<'1';
	}
	else{
		cout<<'0';
	} 
	return 0;
} 
