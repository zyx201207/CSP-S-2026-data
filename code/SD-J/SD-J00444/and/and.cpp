#include<bits/stdc++.h>

using namespace std;
int a[200005];
int dp[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1)
	{
		cout << maxn;
		return 0;
	}
	else if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans&=a[i];
		}
		cout << ans;
		return 0;
	}
	else if(m==2)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout << ans;
		return 0;
	}
	return 0;
}

