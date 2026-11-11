#include<bits/stdc++.h>
using namespace std;

int c,t,n,k;
int cnt[100005];
int con[100005][100005];
int maxn=0;

void dfs(int st,int lst,int ct)
{
	for(int i=1;i<=cnt[st];i++)
	{
		dfs(i,st,ct+1);
	}
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			cnt[u]++;
			cnt[v]++;
			con[u][cnt[u]]=v;
			con[v][cnt[v]]=u;
		}
		for(int i=1;i<=n;i++)
		{
			dfs(i,0,1);
		}
	}
	return 0;
}
