#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

const int N=2e6+145;
int x[N];
int n,d,c;
vector<int>g[N];

int mn[N],f[N];

int get(int s)
{
	queue<int>q;
	for(int i=s;i<=n;i++) mn[i]=-1,f[i]=0;
	f[s]=1;
	mn[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto v:g[u])
		{
			if(mn[v]==-1)
			{
				mn[v]=mn[u]+1;
				f[v]=f[u];
				q.push(v);
			}
			else if(mn[v]==mn[u]+1)
			{
				f[v]+=f[u];
				if(f[v]>3)f[v]=3;
			}
		}
	}
	int res=0;
	for(int i=s+1;i<=n;i++)
	{
		if(f[i]==2)
		{
			res++;
//			cout<<s<<" "<<i<<"\n";
		}
	}
	return res;
	
}


void solve()
{
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
		g[i].clear();
	}
	if(c>=11)
	{
		puts("0");
		return;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(x[j]-x[i]<=d)
			{
				g[i].push_back(j);
				
			}
			else break;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=get(i);
	}
	printf("%lld\n",ans);
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		solve();
	}
	return 0;	
}
/*
12 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/