#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
int cnt[35];
vector<int> v;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=30;i>=0;i--)
	{
		for(int j=1;j<=n;j++)
		{
			cnt[i]+=((a[j]&(1<<i))!=0);
		}
	}
	for(int i=30;i>=0;i--)
	{
		if(cnt[i]<m)
		{
			continue;
		}
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			bool f=1;
			for(int k:v)
			{
				f&=((a[j]&(1<<k))!=0);
			}
			sum+=(f&((a[j]&(1<<i))!=0));
		}
		if(sum>=m)
		{
			v.push_back(i);
		}
	}
	int ans=0;
	for(int i:v)
	{
		ans+=(1<<i);
	}
	cout<<ans;
	return 0;
}
