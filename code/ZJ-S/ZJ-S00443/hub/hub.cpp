#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,u,v,l[200005],maxn[200005],ltk;
vector<int> tr[200005];
int gt(int p,int x)
{
	return (p>>(x-1))&1;
}
void dfs(int s,int p,int f)
{
	int t=0,tt=0;
	l[p] = maxn[p] = 0;
	if(gt(s,p)==1 && gt(s,f)==0)
		ltk++;
	for(int i : tr[p])
	{
		if(i!=f)
		{
			dfs(s,i,p);
			maxn[p] = max(maxn[i],maxn[p]);
			l[p] = max(l[i],l[p]);
			if(l[i] >= t)
			{
				tt = t;
				t = l[i];
			}
			else if(l[i] >= tt)
			{
				tt = l[i];
			}
		}
	}
	if(gt(s,p))
		l[p] = 0;
	else
		l[p]++,maxn[p] = max(maxn[p],t+tt+1);
	maxn[p] = max(maxn[p],l[p]);
}
int check(int g)
{
	ltk = 0;
	dfs(g,1,0);
	if(ltk > 2)
		return 1e18;
	else
		return maxn[1];
}
signed main()
{
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i = 1;i < n;i++)
		{
			cin>>u>>v;
			tr[u].push_back(v);
			tr[v].push_back(u);
		}
		int ans = 1e18;
		for(int i = 1;i < (1<<n);i++)
		{
			if(__builtin_popcount(i) != k)
			{
				continue;
			}
			else
			{
				ans = min(check(i),ans);
			}
		}
		for(int i = 1;i <= n;i++)
			tr[i].clear();
		cout<<ans<<'\n';
	}
	return 0;
}
