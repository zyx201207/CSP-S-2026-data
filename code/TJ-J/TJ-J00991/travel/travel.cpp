#include<bits/stdc++.h>
using namespace std;
long long n,t,x,y;
string xx,yy;
char c[100005];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	c['A']=0,c['B']=0,c['C']=0,c['D']=1,c['F']=1;
	cin>>x>>xx>>y>>yy;
	if(x==y) cout<<1;
	else cout<<0;
	if(x==y&&(xx[0]-'0')*10+xx[1]-'0'==(yy[0]-'0')*10+yy[1]-'0') cout<<1;
	else cout<<0;
	if(x==y&&(xx[0]-'0')*10+xx[1]-'0'==(yy[0]-'0')*10+yy[1]-'0'&&c[xx[2]]==c[yy[2]]) cout<<1;
	else cout<<0;
	if(x==y&&(xx[0]-'0')*10+xx[1]-'0'==(yy[0]-'0')*10+yy[1]-'0'&&c[xx[2]]==c[yy[2]]&&(abs(xx[2]-yy[2])==1||xx[2]=='D'&&yy[2]=='F'||xx[2]=='F'&&yy[2]=='D')) cout<<1;
	else cout<<0;
	return 0;
}
