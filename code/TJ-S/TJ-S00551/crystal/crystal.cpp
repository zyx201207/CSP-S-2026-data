#include <bits/stdc++.h>
using namespace std;
int a[500010];
int zd(int x,int y)
{
	int cnt =0,sy =y,zz= x;
	while(sy>=0)
	{
		if((a[x]-a[zz])<=sy)
		{
			sy-=a[x];
			sy+=a[zz];
			cnt++;
		}
		else
		{
			sy = -1;
		}
		zz--;
		if(zz==0)
		{
			return cnt;
		}
	}
	return cnt;
}
int main ()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,maxn = -1e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		int l = zd(i,m);
		maxn = max(maxn,l);
	}
	cout<<maxn;
}

