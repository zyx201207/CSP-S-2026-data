#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2000006;
long long n;
long long d;
long long a[MAXN];
long long f[MAXN];
long long g[MAXN];
vector<long long> vec[MAXN];
void work()
{
	long long ans = 0;
	cin>>n>>d;
	for(long long i = 1; i<=n; i++)
	{
		cin>>a[i];
	}
	for(long long i = 1; i<=n; i++)
	{
		vec[i].clear();
		for(long long j = i+1; j<=n; j++)
		{
			if(a[j]-a[i]<=d)
			{
				vec[i].push_back(j);
			}
		}
	}
	for(long long st = 1; st<=n; st++)
	{
		for(long long i = st; i<=n; i++)
		{
			f[i] = 0x3f3f3f3f;
			g[i] = 0;
		}
		f[st] = 0;
		g[st] = 1;
		queue<long long> q;
		q.push(st);
		while(!q.empty())
		{
			long long u = q.front();
			q.pop();
			for(long long v : vec[u])
			{
				if(f[v]>f[u]+1)
				{
					f[v] = f[u]+1;
					g[v] = g[u];
					q.push(v);
				}
				else if(f[v] == f[u]+1)
				{
					g[v]++;
				}
			}
		}
		for(long long i = st+1; i<=n; i++)
		{
			if(g[i] == 2)
			{
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c;
	long long t;
	cin>>c>>t;
	while(t--)
	{
		work();
	}	
	return 0;
}
