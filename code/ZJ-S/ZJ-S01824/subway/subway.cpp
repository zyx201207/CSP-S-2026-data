#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll c,n,m,d,q,w[500010],k[510],a[510][1010],t[510][1010],x[100010],y[100010],ans=1e18;

bool g[510][1010],vis[1010];
int ct[1010];

void dfs(ll curl,ll curs,ll end,ll time)
{
	if(curs==end)
	{
		ans=min(ans,time);
		return;
	}
	for(int j=1;j<=k[curl];j++)
	{
		//cout<<"current line:"<<curl<<" current station:"<<j<<"\n";
		if(j==curs)continue;
		if(ct[j]>1)
		{
			for(int i=1;i<=n;i++)
			{
				if(g[i][j]&&i!=curl&&!vis[j])
				{
					vis[j]=1;
					dfs(i,j,end,time+t[i][j]+t[curl][j]);
					vis[j]=0;
				}
			}
		}
		else if(j==end)
		{
			ans=min(ans,time);
			return;
		}
	}
	return;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			g[i][j]=1;
			ct[j]++;
		}
	}
	for(int i=1;i<=q;i++)
	{
		ans=1e18;
		cin>>x[i]>>y[i];
		for(int j=1;j<=n;j++)
		{
			if(g[j][x[i]])
			{
				dfs(j,x[i],y[i],t[j][x[i]]);
			}
		}
		cout<<w[x[i]]+ans+w[y[i]]<<'\n';
	}
	return 0;
}

