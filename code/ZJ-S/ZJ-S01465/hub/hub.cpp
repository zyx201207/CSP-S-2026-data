#include <bits/stdc++.h>
using namespace std;

int f[1005][1005];

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin >> c >> T;
	while(T--)
	{
		int n,op;
		cin >> n >> op;
		int x,maxn = 0;
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				if(i != j)
					f[i][j] = 1e9;
		for(int i = 1;i < n;i++)
		{
			int u,v;
			cin >> u >> v;
			f[u][v] = 1;
			f[v][u] = 1;
		}
		for(int k = 1;k <= n;k++)
			for(int i = 1;i <= n;i++)
				for(int j = 1;j <= n;j++)
					if(i != j && i != k && j != k)
						f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
		int minn = 1e9;
		for(int i = 1;i <= n;i++)
		{
			int num = 0;
			for(int j = 1;j <= n;j++)
				num += f[i][j];
			minn = min(minn,num);
		}
		cout << minn;
	}
	return 0;
}
