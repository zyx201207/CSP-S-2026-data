#include<bits/stdc++.h>
using namespace std;
long long int sum,n,a[200100],s[200200],r,l,rz,lz,rs,ls,da;
char c[200100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {cin>>a[i]>>c[i];s[i]=s[i-1]+a[i];}
	l=1;
	ls=a[1];
	r=n;
	rs=a[n];
	while(l<r)
	{
		if(ls<=rs) {if(c[l]!=c[r]) da+=ls;rs-=ls;ls=0;}
		else {if(c[l]!=c[r]) da+=rs;ls-=rs;rs=0;}
		if(ls==0) {l++;ls=a[l];}
		if(rs==0) {r--;rs=a[r];}
	}
	cout<<da;
}
