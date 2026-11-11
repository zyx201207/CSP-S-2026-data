#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000010];
int q[1000010];
int qq[1000010];
bool f[1000010];
bool ff[1000010];
int n,k;
int ans;
void bbfs(int u)
{
	int h=1,t=0;
	q[++t]=u;
	ff[u]=1;
	while(h<=t)
	{
		int x=q[h++];
		for (int i=0;i<v[x].size();i++)
			if(!ff[v[x][i]]&&f[v[x][i]])
				ff[v[x][i]]=1,q[++t]=v[x][i];
	}
}
int bbbfs(int u)
{
	int h=1,t=0;
	q[++t]=u;
	qq[t]=0;
	ff[u]=1;
	while(h<=t)
	{
		int x=q[h];
		int xxx=qq[h++];
		for (int i=0;i<v[x].size();i++)
			if(!ff[v[x][i]])
			{
				q[++t]=v[x][i];
				qq[t]=xxx+1;
				ff[v[x][i]]=1;
				if(f[v[x][i]]) return xxx+1;
			}
	}
}
void ddfs(int u,int s)
{
	if(n-u+1+s<k) return ;
	if(s>=k)
	{
		int x=0;
		for (int i=1;i<=n;i++) ff[i]=0;
		for (int i=1;i<=n;i++)
			if(f[i]&&!ff[i])
				x++,bbfs(i);
		if(x>2) return ;
		int sum=0;
		for (int i=1;i<=n;i++)
			if(!f[i])
			{
				for (int j=1;j<=n;j++) ff[j]=0;
				sum=max(sum,bbbfs(i));
			}
		ans=min(ans,sum);
		return ;
	}
	ddfs(u+1,s);
	f[u]=1;
	ddfs(u+1,s+1);
	f[u]=0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;i++) v[i].clear();
		for (int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		ans=INT_MAX;
		ddfs(1,0);
		printf("%d\n",ans);
	} 
	return 0;
}
