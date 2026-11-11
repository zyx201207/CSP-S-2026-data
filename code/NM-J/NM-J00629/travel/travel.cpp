#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
char a,b;
int a1,b1,a2,b2;
scanf("%d%d%c%d%d%c",&a1,&a2,&a,&b1,&b2,&b);
if(a1==b1) {cout<<1;}
else{cout<<"0000";return 0;}
if(a2==b2){ cout<<1;}
else{cout<<0;}
if(('C'-a>=0&&'C'-b>=0)||('C'-a<0&&'C'-b<0)) {cout<<1;
	if('C'-a>=0&&'C'-b>=0){
		if(abs(a-b)==1) cout<<1;
		else cout<<0;
		}
	else {
		if(abs(a-b)==2) cout<<1;
		else cout<<0;
		}
	
	
	}
else{ cout<<0<<0;}





return 0;
}
