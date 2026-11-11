#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+10,M = 1e3+10,K = 510;
int w[N],a[K][M],t[K][M],k[M];
int f[M][M];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	for (int i = 0;i < M;i++)
		for (int j = 0;j < M;j++) f[i][j] = 0x3f3f3f3f3f3f3f3f;
		
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for (int i = 1;i <= m;i++) cin>>w[i];
	for (int i = 1;i <= n;i++)
	{
		cin>>k[i];
		for (int j = 1;j <= k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j < k[i];j++)
		{
			for (int z = j+1;z <= k[i];z++)
				f[a[i][j]][a[i][z]] = min(f[a[i][j]][a[i][z]],t[i][j]+t[i][z]),f[a[i][z]][a[i][j]] = min(f[a[i][z]][a[i][j]],t[i][z]+t[i][j]);
		}
	}
	
//	for (int i = 1;i <= m;i++)
//		{
//			for (int j = 1;j <= m;j++)
//			{
//				if(f[i][j] == 0x3f3f3f3f3f3f3f3f) cout<<0<<' ';
//				else cout<<f[i][j]<<' ';
//			}
//			cout<<'\n';
//		}
	
	for (int z = 1;z <= m;z++)
	{
		for (int i = 1;i <= m;i++)
		{
			for (int j = 1;j <= m;j++)
			{
				f[i][j] = min(f[i][j],f[i][z]+f[z][j]);
			}
		}
	}
	
	while (q--)
	{
		int x,y;cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
 } 
