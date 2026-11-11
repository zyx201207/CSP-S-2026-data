#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
const ll N=5e3;
ll  c,T;
ll n,a[N],d,dis[N][N],dist,sm,ans;
bool v[N];
vector<vector<ll> > g(N);
void bfs(ll st)
{
	
	dis[st][st]=0;
	queue<ll> q;
	q.push(st);
	while(!q.empty())
	{
		ll nx=q.front();
		q.pop();
		for(auto i:g[nx])
		{
			if(dis[st][i]==inf)
			{
				dis[st][i]=dis[st][nx]+1;
				q.push(i);
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(abs(a[i]-a[j])>d) break;
				else
				{
					if(i!=j &&abs(a[i]-a[j])<=d)
					{
						g[i].push_back(j);
						g[j].push_back(i);
					}
				}
			}
		}
		for(int i=1;i<=n;i++) fill(dis[i]+1,dis[i]+1+n,inf);
		for(int i=1;i<=n;i++)
		{
			//memset(v,0,sizeof(v));
			bfs(i);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				dist=dis[i][j];sm=0;
				for(int k=i+1;k<j;k++)
				{
					
					if(dis[k][j]+dis[i][k]==dist)
					{
						sm++;
						if(sm>2)break;
					}
				}
				if(sm==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
