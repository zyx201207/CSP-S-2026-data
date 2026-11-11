#include <bits/stdc++.h>
#include <stdio.h>
#include <cstdio>
using namespace std;
const int N=5e5+5; 
long long n,m,a[N],zz,yy,ans,ky;
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a[0]=-1e12-5;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(n>5000)
	{
		int dc=a[2]-a[1];
		for(int i=1;i<=n;i++)
		{
			yy=(1+i)*i/2*dc;
			cout<<yy<<endl;
			if(yy>m)
			{
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		ky=0;
		yy=0;
		for(int j=i;j>=1;j--)
		{
			yy+=a[i]-a[j];
			if(yy<=m)ky++;
		}
		ans=max(ans,ky);
	} 
	cout<<ans;
	return 0;
}