#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	int c,d;
	char e,f;
	cin>>a>>c>>e>>b>>d>>f;
	if(e=='F')e='E';
	if(f=='F')f='E';
	if(a==b){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}if(c==d){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}if((e<='C' && f<='C') ||(e>'C' && f>'C')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(e-f)==1){
		cout<<1;
	}else{
		cout<<0;
	}
}
