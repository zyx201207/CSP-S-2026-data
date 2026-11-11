#include<bits/stdc++.h>
using namespace std;
int fa[1000010][22],dep[1000010],ans,t,n,k;
vector<int>v[1000010];
bool chosen[1000010],vis[1000010];
void bl(int x,int f)
{
	fa[x][0]=f;
	dep[x]=dep[f]+1;
	for(int i=1;i<=20;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(auto to:v[x])
		if(to!=f)
			bl(to,x);
}
int lca(int x,int y)
{
	if(dep[x]>dep[y])
		for(int i=20;i>=0;i--)
			if(dep[fa[x][i]]>=dep[y])
				x=fa[x][i];
	if(dep[y]>dep[x])
		for(int i=20;i>=0;i--)
			if(dep[fa[y][i]]>=dep[x])
				y=fa[y][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void dfs(int x,int cnt)
{
	if(cnt==k)
	{
		for(int i=1;i<=n;i++) vis[i]=0;
		int checker=0;
		for(int i=1;i<=n;i++)
		{
			if(chosen[i]&&!vis[i])
			{
				checker++;
				if(checker>2)
					return;
				vis[i]=1;
				queue<int>q;
				q.push(i);
				while(!q.empty())
				{
					int now=q.front();
					q.pop();
					for(auto to:v[now])
						if(chosen[to]&&!vis[to])
							vis[to]=1,q.push(to);
				}
			}
		}
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			if(chosen[i]) continue;
			int minn=INT_MAX;
			for(int j=1;j<=n;j++)
				if(chosen[j])
					minn=min(minn,dep[j]+dep[i]-dep[lca(i,j)]*2);
			maxn=max(maxn,minn);
		}
		ans=min(ans,maxn);
		return;
	}
	if(x==n+1) return;
	dfs(x+1,cnt);
	chosen[x]=1;
	dfs(x+1,cnt+1);
	chosen[x]=0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%*d%d",&t);
	while(t--)
	{
		for(int i=1;i<=n;i++) v[i].clear(),dep[i]=0;
		scanf("%d%d",&n,&k);
		if(n<=20)
		{
			for(int i=1;i<n;i++)
			{
				int x,y;
				scanf("%d%d",&x,&y);
				v[x].push_back(y);
				v[y].push_back(x);
			}
			bl(1,1);
			ans=INT_MAX;
			dfs(1,0);
			printf("%d\n",ans);
		}
		else
		{
			if(k>=n/2)
				printf("1\n");
			else
				printf("%d\n",n/2-1-(k-1)/2);
		}
	}
	return 0;
}
//安得自动AC机，提交天下题目俱通过！风雨不动安如山。呜呼！何时突兀拿到S一等，J组三等受退役亦足！