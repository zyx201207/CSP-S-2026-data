#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],b[500010],c[500010],sum,ans=0,cnt;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
		c[i]=c[i-1]+1LL*b[i]*(i-1);
	}
	c[n+1]=c[n]+m+10;
	for(int i=1;i<=n;i++)
	{
		
		while(c[cnt]-c[i]-1LL*(a[cnt]-a[i])*(i-1)<=m)
		{
			cnt++;
		}
		ans=max(ans,cnt-i);
		if(ans>n+1-i)
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}
