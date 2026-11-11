#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<int,int> PII;

const int N = 2e4 + 5;

int c, n, m, d, q, w[N], a[505][N], t[505][N];

vector<PII> g[N];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	
	for(int i = 1; i <= q; i++)
	{
		int x, y;
		cin >> x >> y;
		
	}
	return 0;
}
