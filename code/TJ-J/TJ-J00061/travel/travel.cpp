#include<bits/stdc++.h>
using namespace std;
string ra,rb,xa,xb,s,t; 
string s1,t1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ra>>rb>>xa>>xb;
	if(ra == xa){
		cout<<"1";
	}
	if(ra!=xa){
		cout<<"0000";
		return  0;
	}
	
	s = rb.substr(0,2);
	t = xb.substr(0,2);
	if(s  == t){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	s1 =rb.substr(2,1);
	t1 =xb.substr(2,1);
	if( s1<= "C"&&t1>="D"){
		cout<<"00";
		return 0;
	}
	else{
		cout<<"1";
	}
	if(s1=="A"&&t1 == "C"){
		cout<<"0";
	}
	else{
		cout<<"1";
	}
	
	return 0;
}



