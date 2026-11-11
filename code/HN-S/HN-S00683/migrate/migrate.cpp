#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define I using
#define AK namespace
#define IOI std;
I AK IOI
int C,T,a[100005],n,d,l[100005],ans;
int dfs(int t)
{
	if(t>=n)return 0;
	if(l[t]==0)return 0;
	if(l[t]>2)return 0;
	if(l[t]==2&&t+3<=n&&a[t+3]-a[t+1]<=d)
	{
		dfs(t+1);
		dfs(t+2);
		ans++;
		return 1;
	}
	dfs(t+1);
	return 0;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<n;i++)
		{
			l[i]=0;
			int j=i+1;
			while(a[j]-a[i]<=d&&j<=n)
			{
				j++;
				l[i]++;
			}
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}

