#include<bits/stdc++.h>
using namespace std;
int n,zd,t=2;
long long m,a[500005],b[500005],s,x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++)
	{
		while(s>m-(i-t+1)*b[i])
		{
			s=s-x;
			x=x-b[t];
			t++;
		}
		s=s+(i-t+1)*b[i];
		x=x+b[i];
		zd=max(zd,i-t+1);
	}
	cout<<zd+1;
	return 0;
}