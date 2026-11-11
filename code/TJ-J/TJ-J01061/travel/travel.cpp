#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	int p1,p2;
	int h1,h2;
	cin>>p1>>h1;
	cin>>s[0];
	cin>>p2>>h2;
	cin>>s[1];
	
	if(p1==p2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(h1==h2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if((s[0]<='C' and s[1]<='C') or (s[0]>='D' and s[1]<'D' and s[0]<='F' and s[1]<='F')){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(s[1]-s[0]==1 or s[0]-s[1]==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}

