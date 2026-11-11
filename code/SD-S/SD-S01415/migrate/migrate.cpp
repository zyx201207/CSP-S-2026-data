#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
int n;
ll a[N],d,ans;
unordered_map<int,ll>mp[N];
set<ll>s[N];
void dfs(int x,int cnt)
{
	s[x].insert(cnt);
	mp[x][cnt]++;
	if(x==n+1)return;
	for(int i=x+1;i<=n;i++)if(a[i]-a[x]<=d)dfs(i,cnt+1);
}
void get(int x)
{
	for(int i=x;i<=n;i++)
	{
		if(s[i].size())
		{
			auto it=s[i].begin();
			if(mp[i][*it]==2)ans++;
		}
	}
}
void init(int x)
{
	for(int i=x;i<=n;i++)mp[i].clear(),s[i].clear();
}
void solve()
{
	ans=0;
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(n<=9)
	{
		for(int i=1;i<=n;i++)
		{
			dfs(i,0);
			get(i);
			init(i);
		}
	}
	printf("%lld\n",ans);
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int id,t;
	cin>>id>>t;
	while(t--)solve();
	return 0;
}
