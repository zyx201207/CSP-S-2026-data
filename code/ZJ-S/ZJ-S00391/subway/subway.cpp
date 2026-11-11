#include<bits/stdc++.h>
using namespace std;
#define int long long
int Fl[505][505],a[30005];
//vector<int>G[];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,c,d,q,sum=0,ans=1;
	cin>>c>>n>>m>>d>>q;
	if(c<=6)
	{
		for(int i=1;i<=m;i++)cin>>a[i];
		for(int i=0;i<501;i++)for(int j=0;j<501;j++)Fl[i][j]=1e18;
		for(int i=0;i<n;i++)
		{
			int k,a,t;
			cin>>k;
			for(int j=0;j<k;j++)cin>>a>>t,Fl[a][i+m+10]=Fl[i+m+10][a]=t;
		}
		for(int k=1;k<=n+m+15;k++)for(int i=2;i<=n+m+15;i++)for(int j=1;j<i;j++)Fl[i][j]=Fl[j][i]=min(Fl[i][k]+Fl[k][j],Fl[i][j]);
		for(int i=0;i<q;i++)
		{
			int x,y;
			cin>>x>>y;
			cout<<Fl[x][y]+a[x]+a[y]<<'\n';
		}
	}
	else if(c<=11)
	{
		for(int i=1;i<=m;i++)cin>>a[i];
		for(int i=0;i<501;i++)for(int j=0;j<501;j++)Fl[i][j]=1e18;
		for(int i=0;i<n;i++)
		{
			int k,a,t,a2,t2;
			cin>>k>>a>>t;
			if(k==2)cin>>a2>>t2,Fl[a][a2]=Fl[a2][a]=t+t2;
		}
		for(int k=1;k<=m;k++)for(int i=2;i<=m;i++)for(int j=1;j<i;j++)Fl[i][j]=Fl[j][i]=min(Fl[i][k]+Fl[k][j],Fl[i][j]);
		for(int i=0;i<q;i++)
		{
			int x,y;
			cin>>x>>y;
			cout<<Fl[x][y]+a[x]+a[y]<<'\n';
		}
	}
	else if(c<=19)
	{
		for(int i=1;i<=m;i++)cin>>a[i];
		for(int i=0;i<n;i++)
		{
			int k,a,t;
			cin>>k;
			for(int j=0;j<k;j++)cin>>a>>t;
		}
		for(int k=1;k<=m;k++)for(int i=2;i<=m;i++)for(int j=1;j<i;j++)Fl[i][j]=Fl[j][i]=min(Fl[i][k]+Fl[k][j],Fl[i][j]);
		for(int i=0;i<q;i++)
		{
			int x,y;
			cin>>x>>y;
			cout<<Fl[x][y]+a[x]+a[y]<<'\n';
		}
	}
	if(c<=21)
	{
		for(int i=1;i<=m;i++)cin>>a[i];
		for(int i=0;i<501;i++)for(int j=0;j<501;j++)Fl[i][j]=1e18;
		int ans[2];fill(ans,ans+2,1e18);
		for(int i=0;i<n;i++)
		{
			int k,a,t;
			cin>>k;
			for(int j=0;j<k;j++)cin>>a>>t,ans[i]=min(Fl[a][i+m+10]=Fl[i+m+10][a]=t,ans[i]);
		}
		for(int i=0;i<q;i++)
		{
			int x,y;
			cin>>x>>y;
			cout<<max({Fl[m+10][x]+Fl[m+10][y],Fl[m+11][x]+Fl[m+11][y],Fl[m+10][x]+Fl[m+11][y]+ans[0]+ans[1],Fl[m+11][x]+Fl[m+10][y]+ans[0]+ans[1]})
+a[x]+a[y]<<'\n';
		}
	}
	else
	{
		for(int i=1;i<=m;i++)cin>>a[i];
		for(int i=0;i<501;i++)for(int j=0;j<501;j++)Fl[i][j]=1e18;
		for(int i=0;i<n;i++)
		{
			int k,a,t;
			cin>>k;
			for(int j=0;j<k;j++)cin>>a>>t,Fl[a][i+m+10]=Fl[i+m+10][a]=t;
		}
		for(int k=1;k<=n+m+15;k++)for(int i=2;i<=n+m+15;i++)for(int j=1;j<i;j++)Fl[i][j]=Fl[j][i]=min(Fl[i][k]+Fl[k][j],Fl[i][j]);
		for(int i=0;i<q;i++)
		{
			int x,y;
			cin>>x>>y;
			cout<<Fl[x][y]+a[x]+a[y]<<'\n';
		}
	}
	return 0;
}