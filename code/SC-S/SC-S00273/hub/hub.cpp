/*
	剩1小时了
	时间紧迫。
	
	打T4暴力。
	
	给定一颗树， 要求在树中选取一些节点，满足节点总数量为k且节点被分为最多两个联通快。
	
	求所有节点到最近的被选中的节点的距离最大值。 
	
	15分暴力2进制枚举。 
	
	
*/
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int C,T; 
int n,k;
int head[N],ver[N],nxt[N],tot;
inline void add(int x,int y)
{
	ver[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
	return ;
}
bool vis[N],vis1[N];
void dfs1(int x,int fa)
{
	vis1[x]=true;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(y==fa||!vis[y]) continue;
		dfs1(y,x);
	}
}
int dfs2(int x,int fa)
{
	if(vis[x]) return 0;
	int minn=20;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(y==fa) continue;
		minn=min(minn,dfs2(y,x)+1);
	}
	return minn;
}
inline void solve()
{
	tot=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) head[i]=0;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}	
	if(C<=3) 
	{
		int ans=20;
		for(int i=0;i<(1<<n);i++)
		{
			int cnt=0;
			for(int j=0;j<n;j++)
			{
				if(i&(1<<j)) cnt++;
			}
			if(cnt==k)
			{
				int s=0;
				for(int j=1;j<=n;j++)
				{	
					vis[j]=0;
					vis1[j]=0;
					if(i&(1<<(j-1))) 
					{
						vis[j]=true;
						s=j;
					}
				}
				dfs1(s,0);
				for(int j=1;j<=n;j++)
				{	
					if(vis[j]&&!vis1[j]) s=j;
				}
				if(s)
				{
					bool flag=false;
					dfs1(s,0);
					for(int j=1;j<=n;j++)
					{
						if(vis[j]&&!vis1[j])
						{
							flag=true;
							break;
						} 
					}
					if(flag) continue;
				}
				int now=0;
				for(int j=1;j<=n;j++)
				{
					now=max(now,dfs2(j,0));	
				}
				ans=min(ans,now);
			}
		}
		cout<<ans<<'\n';
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	cin>>C>>T;
	while(T--) solve();
	return 0;
}