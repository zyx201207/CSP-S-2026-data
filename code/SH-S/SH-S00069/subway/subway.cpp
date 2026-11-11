#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;//m:5e5   n:500    d:20    q:1e5
struct stationn{
	int w;
	vector<int> lt;
	vector<int> tt;
}s[500005];
long long f[505][505];
const long long INF=1e18+10;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>s[i].w;
	for(int i=1;i<=n;i++)
	{
		int k=0,a=0,t=0;cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a;
			s[a].lt.push_back(i);
			cin>>t;
			s[a].tt.push_back(t);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j) f[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int siz=s[i].lt.size();
		for(int j=0;j<siz;j++)
		{
			for(int k=0;k<siz;k++)
			{
				if(j==k) continue;
				int u=s[i].lt[j],v=s[i].lt[k];
				f[u][v]=min(f[u][v],1ll*(s[i].tt[j]+s[i].tt[k]));
				f[v][u]=min(f[v][u],1ll*(s[i].tt[j]+s[i].tt[k]));
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int i=1;i<=n;i++)
			{
				if(f[i][k]!=INF&&f[k][j]!=INF) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	long long ans=0; 
	int xr=0,yr=0;
	while(q--)
	{
		cin>>xr>>yr;
		ans=INF;
		int s1=s[xr].tt.size();
		int s2=s[yr].tt.size();
		for(int i=0;i<s1;i++)
		{
			for(int j=0;j<s2;j++)
			{
				int u=s[xr].lt[i];
				int v=s[yr].lt[j];
				long long mm=f[u][v]+s[xr].tt[i]+s[yr].tt[j];
				ans=min(ans,mm); 
			}
		}
		ans+=(s[xr].w+s[yr].w);
		cout<<ans<<endl;
	}
	return 0;
}
