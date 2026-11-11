#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,n,m,d,q,a[505][N],k[3],x[N],y[N];
long long t[505][N],w[N];

int z[505][505],lian[505];

void zhaolu()
{	
		
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<=c;i++)
	{
		for(int i=1;i<=m;i++)cin>>w[i];//每一站对应时间 
		for(int i=1;i<=n;i++)
		{
			cin>>k[i];
			for(int j=1;j<=k[i];j++)
			{
				cin>>a[i][j];
				cin>>t[i][j];
			}
		}
		for(int i=1;i<=q;i++)
		{
			cin>>x[i];
			cin>>y[i];
		}
		
		for(int i=1;i<q;i++)//正式处理出行计划 
		{
			int ans=0;
			ans+=w[x[i]]+w[y[i]];
			zhaolu();
			cout<<ans;
		} 
		
	}
	return 0;
}
