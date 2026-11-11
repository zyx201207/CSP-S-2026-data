#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int s[505][500005];
vector<pair<int,int>> l[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++)
	{
		int temp;
		cin >> temp;
		for (int j = 1;j <= temp;j++)
		{
			int u,v;
			cin >> u >> v;
			s[i][u] = v;
			if (j != 1) l[] 
		}
	}
	
	while (q--)
	{
		int s,e;
		cin >> s >> e;
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++) cout << s[i][j] << ' ';
		cout << "\n";
	}
}
