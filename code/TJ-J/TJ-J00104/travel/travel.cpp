#include<bits/stdc++.h>
using namespace std;
char a[2],b[3],c[2],d[3];
bool f=0,g[4];
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	
	if(a[0]==c[0]&&a[1]==c[1]) g[0]=1;
	else {
		cout<<"0000";
		return 0;
	}
	
	if((a[0]==c[0]&&a[1]==c[1])&&(b[0]==d[0]&&b[1]==d[1])) g[1]=1;
	else {
		cout<<1000;
		return 0;
	}
	
	if(((a[0]==c[0]&&a[1]==c[1])&&(b[0]==d[0]&&b[1]==d[1]))&&((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))) g[2]=1;
	else if(((a[0]==c[0]&&a[1]==c[1])&&(b[0]==d[0]&&b[1]==d[1]))&&((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))) g[2]=1;
	else {
		cout<<1100;
		return 0;
	}
	
	if(g[2]&&((b[2]==d[2]+1||b[2]==d[2]-1)||((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')))&&((b[2]!='C'||b[2]!='D')&&(d[2]!='C'||d[2]!='D'))) g[3]=1;
	else {
		cout<<1110;
		return 0;
	}
	cout<<g[0]<<g[1]<<g[2]<<g[3];
	return 0;
} 
