#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	char a,b;
	cin>>c1>>s1>>a>>c2>>s2>>b;
	if(c1!=c2){
		cout<<"0";
	}else{
		cout<<"1";
	}
	if(s1==s2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if((a>='A'&&a<='C')&&(b>='A'&&b<='C')){
		cout<<"1";
	}
	else if((a=='D'&&b=='F')||(b=='D'&&a=='F')){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(a-1==b||b-1==a){	
		cout<<"1";
	}
	else if(a=='D'&&b=='F'){
		cout<<"1";
	} 
	else{
		cout<<"0";
	}
	return 0;
}
