#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1;
	int sum=0,ans=1,maxn=0;
	while(l<=r and r<n)
	{
		if(sum+ans*(a[r+1]-a[r])<=m)
		{
			sum+=ans*(a[r+1]-a[r]);
			r++;
			ans++;
		}
		else
		{
			sum-=(a[r]-a[l]);
			l++;
			ans--;
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}
