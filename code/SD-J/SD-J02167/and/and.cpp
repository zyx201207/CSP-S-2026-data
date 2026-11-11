#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,m;
	cin>>n>>m;
	int ans,maxn;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ans=a[1];
	maxn=a[1];
	for(int i=2;i<=n;i++)
	{
		ans=ans&a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	if(m==n)
	{
		cout<<ans;
		return 0;
	}
	maxn=-1;
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}
	return 0;
}
