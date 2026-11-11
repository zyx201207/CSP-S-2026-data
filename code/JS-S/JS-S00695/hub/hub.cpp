#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
vector<int> e[1000020];
int dis[15][15];
void dfs1(int x,int f,int *dis)
{
	for(int v:e[x]) if(v!=f) dis[v]=dis[x]+1,dfs1(v,x,dis);
}
bool vis[15];
void dfs2(int x,int f,int s)
{
	vis[x]=true;
	for(int v:e[x]) if(v!=f && (s>>(v-1)&1)) dfs2(v,x,s);
}
int solve()
{
	cin>>n>>m;ans=n;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	for(int i=1;i<=n;i++) dis[i][i]=0,dfs1(i,0,dis[i]);
	for(int s=0;s<(1<<n);s++)
	{
		if(__builtin_popcount(s)!=m) continue;
		memset(vis,0,sizeof(vis));
		int cnt=0;
		for(int i=1;i<=n;i++) if((s>>(i-1)&1) && !vis[i]) cnt++,dfs2(i,0,s);
		if(cnt>2) continue;
		int cur=0;
		for(int i=1;i<=n;i++)
		{
			int mn=n;
			for(int j=1;j<=n;j++) if(s>>(j-1)&1) mn=min(mn,dis[i][j]);
			cur=max(cur,mn);
		}
		ans=min(ans,cur);
	}
	return ans;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int tid,t;
	cin>>tid>>t;
	while(t--) printf("%d\n",solve());
}
/*
I'm Aukcwduag(encoded), a Grade 12 student.
I won a silver medal in the National Olympiad in Informatics 2026.
Finally, it's time to leave.
Best wishes to every OIer persuing his/her dream.
By the way, the lengths of my codes are 520, 1314, 2026 and 1031 respectively :)
*/
