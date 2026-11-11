#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e2+5;
int c,t;
int n,d;
int x[N];
int f[N][N],g[N][N];
int ans;

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		memset(f,0x3f,sizeof(f));
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++)f[i][i]=0,g[i][i]=1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(x[i]+d>=x[j])f[i][j]=1,g[i][j]=1;
				else break;
		for(int k=1;k<=n;k++)
			for(int i=1;i<k;i++)
				for(int j=k+1;j<=n;j++)
					if(f[i][j]>f[i][k]+f[k][j])
						f[i][j]=f[i][k]+f[k][j],
						g[i][j]=g[i][k]*g[k][j];
					else if(f[i][j]==f[i][k]+f[k][j])
						g[i][j]+=g[i][k]*g[k][j];
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				if(g[i][j]==2)ans++;
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
