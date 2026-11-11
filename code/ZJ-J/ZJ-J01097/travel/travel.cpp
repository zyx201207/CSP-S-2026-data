#include <bits/stdc++.h>
using namespace std;
int x,y,c1,c2;
char a,b,s1[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x=s1[0]*10+s1[1];a=s1[2];
	y=s2[0]*10+s2[1];b=s2[2];
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(x==y) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((a>='D'&&b>='D')||(a<='C'&&b<='C')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((a=='A'&&b=='C')||(a=='C'&&b=='A')) cout<<0;
	else cout<<1;
} 
