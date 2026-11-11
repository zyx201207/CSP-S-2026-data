#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
bool side(char x,char y){
	bool flag1=0,flag2=0;
	if(x=='A'||x=='B'||x=='C') flag1=1;
	if(y=='A'||y=='B'||y=='C') flag2=1;
	return flag1==flag2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string  a,b,c,d;
	bool f1,f2;
	cin>>a>>b>>c>>d; 
	if(a==c) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	string e="",f="";
	e+=b[0];
	f+=d[0];
	e+=b[1];
	f+=d[1];
	if(e==f) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	char g=b[2],h=d[2];
	
	if(side(g,h)) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(g-h==1||h-g==1)cout<<1;
	else cout<<0;
	return 0;
}

