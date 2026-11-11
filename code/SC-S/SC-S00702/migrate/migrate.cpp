#include<bits/stdc++.h>
using ll=int;
using namespace std;
ll c,t;
ll n,d;
ll x[8008];
vector<ll>g[8008];
bool df[8008];
ll dst[8008],cnt[8008];
queue<ll>q;
ll res;
void bfs(ll x)
{
	for(int i=1;i<=n;i++)
	{
		dst[i]=1e18;
		cnt[i]=0;
		df[i]=0;
	}
	cnt[x]=1;
	dst[x]=0;
	q.push(x);
	while(q.size())
	{
		ll u=q.front();
		q.pop();
		if(df[u])continue;
		df[u]=1;
		for(auto v:g[u])
		{
			if(dst[v]>dst[u]+1)
			{
				cnt[v]=cnt[u];
				dst[v]=dst[u]+1;
				q.push(v);
			}
			else if(dst[v]==dst[u]+1)
			{
				cnt[v]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]==2)res++;
	}
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			g[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]>d)break;
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
		res=0;
		for(int i=1;i<=n;i++)bfs(i);
		cout<<res/2<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5 
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
0
1
*/