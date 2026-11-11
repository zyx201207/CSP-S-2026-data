#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
const int N=5005,INF=1e9;
int n,k;
bool vis[N],t[N];
class graph
{
public:
	int next[N<<1],to[N<<1],head[N],cnt=1;
	void add(int u,int v)
	{
		next[++cnt]=head[u];
		to[cnt]=v;
		head[u]=cnt;
	}
};
graph e;
void dfs(int now,int pre)
{
	vis[now]=1;
	for(int i=e.head[now];i;i=e.next[i])
	{
		int ver=e.to[i];
		if(ver==pre||!t[ver]||vis[ver]) continue;
		dfs(ver,now);
	}
}
int calc(int st)
{
	queue<int> q;
	int d[N]={};
	q.push(st);
	while(!q.empty())
	{
		int now=q.front(); q.pop();
		for(int i=e.head[now];i;i=e.next[i])
		{
			int ver=e.to[i];
			if(d[ver]) continue;
			d[ver]=d[now]+1;
			if(t[ver])
			  return d[ver];
			q.push(ver);
		}
	}
	return -1;
}
int main()
{
// 	ios_base::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T; cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++)
		{
			cin>>u>>v;
			e.add(u,v);
			e.add(v,u);
		}
		int ans=INF;
		for(int i=0;i<(1<<n);i++)
		{
			int cnt1=0,p=0,tmp=i,flag=0;
			memset(t,0,sizeof(t));
			memset(vis,0,sizeof(vis));
			while(tmp>0) cnt1+=tmp&1,t[++p]=tmp&1,tmp>>=1;
			int res=0;
			if(cnt1==k)
			{
				for(int j=1;j<=n;j++)
					if(!vis[j]&&t[j])
					{
						if(flag<2) dfs(j,-1);
						else
						{
							flag++;
							break;
						}
						flag++;
					}
				if(flag>2) continue;
				for(int j=1;j<=n;j++)
				  if(!t[j]) 
				    res=max(res,calc(j));
			}
			ans=min(ans,res);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
