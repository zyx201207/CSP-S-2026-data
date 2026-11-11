#include<bits/stdc++.h>
using namespace std;
vector<int> a[100001];
int fa[100001],di[100001],f[100001],f1[11],f2[11];
int maxx=0;
int n;
void dfs1(int x)
{
	for(int i=0;i<a[x].size();i++)
	{
		if(fa[x]==a[x][i]) continue;
		fa[a[x][i]]=x;
		di[a[x][i]]=di[x]+1;
		dfs1(a[x][i]);
	}
}
int len(int x,int y)
{
	int ans=0;
	if(di[x]>di[y]) swap(x,y);
	while(di[x]==di[y]) y=fa[y],ans++;
	if(x==y) return ans;
	while(x!=y) y=fa[y],x=fa[x],ans+=2;
	return ans;
 } 
 void dfs3(int x)
 {
 	for(int i=0;i<a[x].size();i++)
	{
		if(f[a[x][i]]) continue;
		f[a[x][i]]=1;
		dfs3(a[x][i]);
	}
 }
void dfs2(int k,int x)
{
	if(k==0)
	{
		memset(f2,0x3f,sizeof(f2));
		int maxx=0;
		for(int i=1;i<=n;i++)
		{
			if(f1[i])
			{
				for(int j=1;j<=m;j++) f2[j]=min(len,f2[j]);
			}
		}
		for(int i=1;i<=n;i++) maxx=max(maxx,f2[i]);
		an=min(an,maxx);
		return ;
	}
	for(int i=x+1;i<=n-k+1;i++)
	{
		f1[i]=1;
		dfs(k-1,i);
		f1[i]=0;
	}
}

void man()
{
	maxx=1000000000;
	
	int k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) a[i].clear();
	memset(fa,0,sizeof(fa));
	memset(di,0,sizeof(di));
	memset(f,0,sizeof(f));
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs1(1);
	for(int i=0;i<(1<<(n-1));i++)
	{
		dfs2(k,0);
	}
	cout<<maxx;
} 
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) man();
	return 0;
}
