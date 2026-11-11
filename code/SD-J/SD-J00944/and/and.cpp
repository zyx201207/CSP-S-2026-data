#include <bits/stdc++.h>
using namespace std;
int n,m,cnt[35];
long long a[200005],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
				ans=max(ans,(a[i]&a[j]));
		}
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
			ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	for(int i=0;i<=31;i++)
	{
		int x=1;
		x=x<<i;
		for(int j=1;j<=n;j++)
		{
			if(a[j]&x)
				cnt[i]++;
		}
	}
	for(int i=31;i>=0;i--)
	{
		int x=1;
		x=x<<i; 
		if(cnt[i]>=m)
			ans+=x;
	}
	cout<<ans;
	return 0;
}
