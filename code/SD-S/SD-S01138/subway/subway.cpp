#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const int inf = 0x3f3f3f3f3f3f3f3f;
int c;
int n,m,d,q;
int w[N];
int a[N];int t[N];
int f[1010][1010];//leadmetohonorfloyd !!!
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c;
	cin >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){for(int j = 1;j <= m;j++){f[i][j] = inf;}}
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
		f[i][i] = 0;
	}
	for(int i = 1;i <= n;i++)
	{
		int n1 = 0;cin >> n1;
		for(int j = 1;j <= n1;j ++)
		{
			cin >> a[j] >> t[j];	
		}
		for(int j = 1;j <= n1;j ++)
		{
			for(int k = 1;k <= n1;k ++)
			{
				if(j != k)
				{
					f[a[j]][a[k]] = t[j] + t[k];
				}
			}
		} 
	}
//	for(int i = 1;i <= m;i++)
//	{
//		for(int j = 1;j <= m;j++)
//		{
//			if(f[i][j] == inf){cout << "*" << " ";continue;}
//			cout << f[i][j] << " ";
//		}
//		cout << endl;
//	}
	for(int k = 1;k <= m;k++)
	{
		for(int i = 1;i <= m;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}
//	for(int i = 1;i <= m;i++)
//	{
//		for(int j = 1;j <= m;j++)
//		{
//			if(f[i][j] == inf){cout << "*" << " ";continue;}
//			cout << f[i][j] << " ";
//		}
//		cout << endl;
//	}
	for(int i = 1;i <= q;i++)
	{
		int u,v;
		cin >> u >> v;
		cout << w[u] + w[v] + f[u][v] << endl;
	}
	return 0;
}


