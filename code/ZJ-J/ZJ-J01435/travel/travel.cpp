#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	int ok=1;
	if(a1==b1){
		cout<<ok;
	}
	else{
		ok=0;
		cout<<ok;
	}
	if(a2[0]==b2[0] && a2[1]==b2[1]){
		cout<<ok;
	}
	else{
		ok=0;
		cout<<ok;
	}
	int a=0,b=0;
	a=int(a2[2]-'A');
	b=int(b2[2]-'A');
	int x=0,y=0;
	if(a>=0 && a<=2){
		x=1;
	}
	else{
		x=2;
	}
	if(b>=0 && b<=2){
		y=1;
	}
	else{
		y=2;
	}
	if(x==y){
		cout<<ok;
	}
	else{
		ok=0;
		cout<<ok;
	}
	if(a+1==b || b+1==a){
		cout<<ok;
	}
	else{
		ok=0;
		cout<<ok;
	}
	return 0;
}
