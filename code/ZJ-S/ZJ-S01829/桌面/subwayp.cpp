#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=10000001;
int w[501],alen[501],a[1001];
int di[501][501],f[501][501];
int c,n,m,d,q;
int x;
signed main()
{
	//cin>>c>>n>>m>>d>>q;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			di[i][j]=INF;
			f[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++)
		di[i][i]=0;
	
	for(int i=1;i<=x;i++)
	{
		int r,s,t;
		cin>>r>>s>>t;
		if(di[r][s]>t)
		{
			di[r][s]=t;
			di[s][r]=t;
		}
	}	
	
	/*for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		cin>>alen[i]
		for(int j=1;j<=2*k[i];j++)
			cin>>a[j];
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=alen[i];j++)
			for(int k=j+1;k<=alen[i];k++)
			{
				int p1=a[2*i],p2=a[2*j],w1=a[2*i+1],w2=a[2*j+1];
				if(w1+w2<d[p1][p2])
				{
					d[p1][p2]=w1+w2;
					d[p2][p1]=w1+w2;
				}
			}*/
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=di[i][j];
			f[j][i]=di[i][j];
		}
	}	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(f[i][j]+f[j][k]<f[i][k])
					f[i][k]=f[i][j]+f[j][k];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)	
			cout<<i<<" "<<j<<" "<<f[i][j]<<'\n';
	return 0;
}
/*void bfs(int now)
{
	
}
void B()
{
	for(int i=1;i<=m;i++)	
		for(int j=1;j<=alen[i];j++)
		{
			int now=a[i][2*j-1];
			poi[i].push_back(now);
			bel[now].push_back(i);
		}
	for(int i=1;i<=n;i++)
	{
		int nlen=bel.size();
		for(int j=0;j<nlen;j++)
			for(int k=j+1;k<nlen;k++)
			{
				int x=bel[i][j],y=bel[i][k];
				e[x][y]=1;
				e[y][x]=1;
			}	
	}
	for(int i=1;i<=q;i++)
	{
		
	}
}*/
