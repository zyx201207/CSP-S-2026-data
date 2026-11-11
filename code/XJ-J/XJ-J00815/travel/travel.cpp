#include<bits/stdc++.h>
using namespace std;
int a,c,x,y;
string b,d;
char n,m;
bool u,o,g,h;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	n=b[2];m=d[2];
	if(m=='A'||m=='B'||m=='C'){
		u=0;
	}
	if(m=='D'||m=='E'){
		u=1;
	}
	if(n=='A'||n=='B'||n=='C'){
		o=0;
	}
	if(n=='D'||n=='E'){
		o=1;
	}
	for(int i=0;i<=1;i++){
		x+=b[i]-'0';
		y+=d[i]-'0';
		if(i==1)break;
		x*=10;
		y*=10;
	}
	if(a==c){
		cout<<1;
		if(x==y){
			cout<<1;
		}
		else cout<<0;
		if(o==u&&x==y){
			cout<<1;
		}
		else cout<<0;
		if(x+1==y||x-1==y)g=1;
		if(m+1==n||m-1==n)h=1;
		if(x==y)g=0;
		if(m==n)h=0;
		if(g==!h&&o==u){
			cout<<1;
		}
		else cout<<0;	
	}             
	else cout<<"0000";
}