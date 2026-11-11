#include<bits/stdc++.h>
#define int long long
#define ex exit(0)
#define sinzo return
#define code 0
using namespace std;
const int N=2e6+10;
int a[N],b[N],c[N],sz[N];
bool vis[N];
int n,m,k,ans,cnt,sum,mx=-1e18,mn=1e18;
struct qaq
{
	int to,next;
}e[N];
int h[N];

void add(int u,int v)
{
	e[++cnt].next=h[u];
	e[cnt].to=v;
	h[u]=cnt;
}
int sumbit(int x)
{
	int ans=0;
	while(x)
	{
		ans++;
		x=x&(x-1);
	}
	return ans;
}
queue<int> q;
void bfs(int x)
{
	while(q.size())q.pop();
	q.push(x);
	sz[x]=0;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		vis[u]=1;
		for(int i=h[u];i;i=e[i].next)
		{
			int v=e[i].to;
			if(vis[v])continue;
			q.push(v);
			sz[v]=min(sz[v],sz[u]+1);
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int T=1,c;
	cin>>c>>T;
	while(T--)
	{
		cnt=0;
		ans=1e16;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		if(c==13||c==14)
		{
			
			continue;
		}
		if(c==7)
		{
			for(int i=2;i<=n;i++)
			{
				for(int j=4;j<=n;j++)
				{
					for(int i=1;i<=n;i++)vis[i]=0;
					for(int i=1;i<=n;i++)sz[i]=1e16;
					bfs(i);
					for(int i=1;i<=n;i++)vis[i]=0;
					bfs(j);
					int bj=0;
					
					for(int i=1;i<=n;i++)bj=max(bj,sz[i]);
//					cout<<i<<' '<<j<<' '<<bj<<endl;
					ans=min(ans,bj);
				}
			}
			cout<<ans<<endl;
			continue;
		}
		
		for(int i=1;i<=(1<<(n+1))-1;i++)
		{
			if(sumbit(i)!=k)continue;
			for(int i=1;i<=n;i++)sz[i]=1e16;
			for(int i=1;i<=n;i++)vis[i]=0;
			for(int j=1;j<=n;j++)
			{
				if(i&(1<<(j-1)))
				{
					bfs(j);
				}
			}
			int bj=0;
			
			for(int i=1;i<=n;i++)bj=max(bj,sz[i]);
			ans=min(ans,bj);
			
			
			
		}
		cout<<ans<<endl;
		
	}
	sinzo code;
}

/*
7 1
5 2
1 2
2 3
3 4
4 5




*/
/*

%%%orz
总结：100+100+14+5=219


*/