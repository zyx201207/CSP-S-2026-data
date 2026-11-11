#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int b1,d1;
bool n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C') n=1;
	if(d[2]=='A'||d[2]=='B'||d[2]=='C') m=1;
	if(a==c) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	} 
	if(b[0]==d[0]&&b[1]==d[1]) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(n==m) cout<<1;
	else{
		cout<<0<<0;
		return 0;
	} 
	if(n==0&&m==0) cout<<1;
	else if(b[2]==d[2]+1||b[2]==d[2]-1) cout<<1;
	else cout<<0;
	return 0;
}
