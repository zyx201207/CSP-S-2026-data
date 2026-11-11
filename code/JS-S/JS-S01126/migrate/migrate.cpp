#include<bits/stdc++.h>
using namespace std;
const int N=2e6+100;
const int INF=1e9;
int c,t,ans,cnt,n,p;
int a[N];
vector <int> g[N];
bool vis[N],f[N];
int d[N],si[N];
struct node{
	int now;
	int depth;
};
void bfs(int u)
{
	queue <node> q;
	node s={u,0};
	q.push(s);
	for(int i=1;i<=n;i++)
		d[i]=INF;
	while(!q.empty())
	{
		node tp=q.front();
		vis[tp.now]=1;
		if(d[tp.now]==INF)
			d[tp.now]=tp.depth;
		else if(d[tp.now]==tp.depth&&f[tp.now]==0)
		{
			cnt++;
			f[tp.now]=1;
		}
		for(int i=0;i<si[tp.now];i++)
		{
			if(vis[g[tp.now][i]]==0)
			{
				q.push({g[tp.now][i],tp.depth+1});
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>p;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			si[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(abs(a[i]-a[j])<=p)
				{
					g[i].push_back(j);
					g[j].push_back(i);
					si[i]++;
					si[j]++;
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				vis[j]=0;
				f[j]=0;
			}
			cnt=0;
			bfs(i);
			ans+=cnt;
		}
		cout<<ans/2<<endl;
	}
	return 0;
}
//luogu:mcc2025
//f**k CCF
