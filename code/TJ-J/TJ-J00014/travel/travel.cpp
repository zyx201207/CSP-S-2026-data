#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else {
		cout<<0; 
	}
	int x,y,m,n;
	x=s1[0];y=s1[1];
	m=s2[0];n=s2[1];
	if(x+y==m+n){
		cout<<1;
	}
	else{
		cout<<0;
	}
	int a,b;
	a=s1[2];b=s2[2];
	if((x+y==m+n)&&(a==b+1||a==b+2||a==b-1||a==b-2)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(a+1==b||a-1==b||b-1==a||b+1==a){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}  
