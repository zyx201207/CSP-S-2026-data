#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[5],b[5],c[5],d[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	bool e=0,f=0,g=0,h=0;
	e=(a[0]==c[0]&&a[1]==c[1]);
	f=(b[0]==d[0]&&b[1]==d[1]&&e);
	if(!f){g=0;h=0;}
	else if(b[2]=='D'&&d[2]=='F'){g=1;h=1;}
	else if(b[2]=='F'&&d[2]=='D'){g=1;h=1;}
	else if(b[2]=='C'&&d[2]=='B'){g=1;h=1;}
	else if(b[2]=='C'&&d[2]=='A'){g=1;h=0;}
	else if(b[2]=='A'&&d[2]=='B'){g=1;h=1;}
	else {g=0;h=0;}
	
	printf("%d%d%d%d",e,f,g,h);
}