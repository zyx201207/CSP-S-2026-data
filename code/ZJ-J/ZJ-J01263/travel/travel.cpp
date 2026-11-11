#include<bits/stdc++.h>
using namespace std;
bool check(char n,char m){
	if(n>m) swap(n,m);
	if(n=='A'&&m=='B') return 1;
	if(n=='A'&&m=='C') return 1;
	if(n=='B'&&m=='C') return 1;
	if(n=='D'&&m=='F') return 1;
	return 0;
}
bool check2(char n,char m){
	if(n>m) swap(n,m);
	if(n=='A'&&m=='B') return 1;
	if(n=='B'&&m=='C') return 1;
	if(n=='D'&&m=='F') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool x,y,z,t;
	x=((a==c)?1:0);
	y=((x&&b[0]==d[0]&&b[1]==d[1])?1:0);
	z=((y&&check(b[2],d[2]))?1:0);
	t=((y&&check2(b[2],d[2]))?1:0);
	cout<<x<<y<<z<<t;
	return 0;
}
