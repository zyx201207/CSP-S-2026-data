#include<bits/stdc++.h>
#define pii pair<int,int>
#define lowbit(x) ((x)&(-(x)))
#define allof(o) (o).begin(),(o).end()
using namespace std;

long long a[2000005];
int dis[2000005];
int cnt[2000005];
int c,t;
int n;
long long d;

long long ans=0;
void dfs(int x,int step)
{
	if(x>n)
		return;
	if(step>dis[x])
		return;
	cnt[x]++;
	for(int y=x+1;y<=n;y++)
		if(a[y]-a[x]<=d)
			dfs(y,step+1);
}

void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ans=0;
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i;j<=n;j++)
			dis[j]=cnt[j]=0;
		int l=i;
		for(int j=i+1;j<=n;j++)
		{
			while(l<j&&a[j]-a[l]>d)
				l++;
			dis[j]=dis[l]+1;
		}
		dfs(i,0);
		for(int j=i+1;j<=n;j++)
			if(cnt[j]==2)
				ans++;
	}
	cout<<ans<<'\n';
}

signed main()
{
#ifndef _WJW_LOCAL_JUDGE
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for(cin>>c>>t;t--;solve());
	return 0;
}