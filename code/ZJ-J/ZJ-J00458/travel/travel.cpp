#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y,n,m;
	string a,b;
	cin>>x>>a>>y>>b;
	if(a[2]=='D')++a[2];
	if(b[2]=='D')++b[2];
	n=(a[0]&15)*10+(a[1]&15);
	m=(b[0]&15)*10+(b[1]&15);
	unsigned c=x==y;
	cout<<c;
	c&=n==m;
	cout<<c;
	if(a[2]>'D'&&b[2]<'D'||a[2]<'D'&&b[2]>'D')c=0;
	cout<<c;
	if(a[2]-b[2]!=1&&a[2]-b[2]!=-1)c=0;
	cout<<c;
}