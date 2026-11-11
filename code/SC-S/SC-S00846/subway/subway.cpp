#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,qq,w[500005],k,x[505][505],u,vv,a,t,fa[505],dis[505],vis[505];
long long ans=0;
struct node{
	long long b,tt;
};
struct bian{
	int a1,a2,l;
	bool operator>(bian aaa)const{
		return l>aaa.l;
	}
}e;
priority_queue <bian,vector <bian> ,greater<bian> > q;
vector<node> v[500005];
vector<node> s[600];
int f(int xx)
{
	if(fa[xx]==xx)
	{
		return xx;
	}
	fa[xx]=f(fa[xx]);
	return fa[xx];
}
void DFS(int xx,int tg)
{
	vis[xx]=1;
	int pp=s[xx].end()-s[xx].begin();
	for(int i=0;i<pp;i++)
	{
		if(!vis[s[xx][i].b])
		{
			x[tg][s[xx][i].b]=x[tg][xx]+s[xx][i].tt;
			DFS(s[xx][i].b,tg);
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(x,0x3f,sizeof(x));//1061109567
	memset(w,0,sizeof(w));
	memset(fa,0,sizeof(fa));
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		while(k--)
		{
			cin>>a>>t;
			v[a].push_back({i,t});
	    }
	}
	for(int i=1;i<=m;i++)
	{
		a=v[i].end()-v[i].begin();
		for(int j=0;j<a;j++)
		{
			for(int o=j+1;o<a;o++)
			{
				x[v[i][j].b][v[i][o].b]=min(x[v[i][j].b][v[i][o].b],v[i][j].tt+v[i][o].tt);
				x[v[i][o].b][v[i][j].b]=min(x[v[i][o].b][v[i][j].b],v[i][j].tt+v[i][o].tt);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(x[i][j]!=4557430888798830399)
			{
				q.push({i,j,x[i][j]});
			}
		}
		fa[i]=i;
	}
	while(!q.empty())
	{
		e=q.top();
		q.pop();
		if(f(e.a1)==f(e.a2))
		{
			continue;
		}
		fa[f(e.a1)]=e.a2;
		s[e.a1].push_back({e.a2,e.l});
		s[e.a2].push_back({e.a1,e.l});
	}
	for(int i=1;i<=n;i++)
	{
		x[i][i]=0;
		DFS(i,i);
	}
	while(qq--)
	{
		cin>>u>>vv;
		ans=1e18;
		a=v[u].end()-v[u].begin();
		t=v[vv].end()-v[vv].begin();
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<t;j++)
			{
				ans=min(ans,v[u][i].tt+v[vv][j].tt+x[v[u][i].b][v[vv][j].b]);
			}
		} 
		ans+=(w[u]+w[vv]);
		cout<<ans<<"\n";
	}
	return 0;
} 