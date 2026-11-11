#include<bits/stdc++.h>
using namespace std;
long long n,m,d,q,a,t,ki,ss,tt;
long long w[500500],g[550][550],e[500500][25],et[500500][25],dist[550][550];
long long h[1005000];
bool st[550];
void dis(int s)
{
	int tt=1,hh=0;
	h[++hh]=s;
	st[s]=1;
	while(tt<=hh)
	{
		int aa=h[tt];
		for(int i=1;i<=n;i++)
		{
			if(g[aa][i]!=-1)
			{
				if(dist[s][i]>dist[s][aa]+g[aa][i])
				{
					if(st[i]==0)
					{
					st[i]=1;
					h[++hh]=i;
					}
					dist[s][i]=dist[s][aa]+g[aa][i];
				}

			}
		}
		st[aa]=0;
		tt++;
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>ki;
		for(int j=1;j<=ki;j++)
		{
			cin>>a>>t;
			e[a][++e[a][0]]=i;
			et[a][++et[a][0]]=t;
		}
	}
	for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                        if(i==j)dist[i][j]=0,g[i][j]=0;
                        else dist[i][j]=0x3f3f3f3f,g[i][j]=-1;

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=e[i][0];j++)
		{
			for(int k=1;k<=e[i][0];k++)
			{
				if(j==k)g[e[i][j]][e[i][k]]=0;
				else g[e[i][j]][e[i][k]]=et[i][j]+et[i][k];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		dis(i);
	}
	for(int i=1;i<=q;i++)
	{
		cin>>ss>>tt;
		if(ss==tt)cout<<0<<endl;
		long long ans=1e15+7;
		for(int j=1;j<=e[ss][0];j++)
			for(int k=1;k<=e[tt][0];k++)
			{
				ans=min(ans,w[ss]+w[tt]+et[ss][j]+et[tt][k]+dist[e[ss][j]][e[tt][k]]);
			}
		cout<<ans<<endl;
	}
}
