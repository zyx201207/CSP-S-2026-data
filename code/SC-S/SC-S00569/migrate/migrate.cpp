#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5010;
int c,t,n,d,x[maxn],f[maxn][maxn],g[maxn][maxn],cnt;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i]; 
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=2e18,g[i][j]=0;
		for(int i=1;i<=n;i++)g[i][i]=1,f[i][i]=0;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
			{
//				if(g[i][j]>2)break;
				for(int k=j+1;x[k]-x[j]<=d&&k<=n;k++)
				{
					if(f[i][k]<f[i][j]+1)continue;
					if(f[i][k]==f[i][j]+1)g[i][k]+=g[i][j];
					else g[i][k]=g[i][j],f[i][k]=f[i][j]+1;
				}
			}
		cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)	
			{
//				if(g[i][j]>2)break;
				if(g[i][j]==2)cnt++;
			}	
		cout<<cnt<<endl;
	}
	return 0;
}
