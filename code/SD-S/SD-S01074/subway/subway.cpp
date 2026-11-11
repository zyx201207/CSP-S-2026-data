#include <bits/stdc++.h>

using namespace std;

const int maxn = 510, maxm = 5e5 + 10;
const long long inf = LONG_LONG_MAX / 2;

long long w[maxm];

int num[maxm], a[maxm][40];
long long t[maxm][40];

long long dis[maxn][maxn];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			int A;
			cin >> A;
			num[A]++;
			a[A][num[A]] = i;
			cin >> t[A][num[A]];
		}
	}
	
//	cout << "||||||||||" << endl << endl;
//	for(int i = 1; i <= m; i++)
//	{
//		cout << num[i] << endl;
//		for(int j = 1; j <= num[i]; j++)
//			cout << a[i][j] << ' ' << t[i][j] << endl;
//		cout << endl;
//	}
//	
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j) dis[i][j] = inf;
	
	for(int i = 1; i <= m; i++)
	{
		for(int t1 = 1; t1 <= num[i]; t1++)
			for(int t2 = t1 + 1; t2 <= num[i]; t2++)
				dis[a[i][t1]][a[i][t2]] = min(dis[a[i][t1]][a[i][t2]], t[i][t1] + t[i][t2]);
	}
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			dis[i][j] = min(dis[i][j], dis[j][i]);
	
	
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
	
//	cout << "|||||||||||||||||" << endl;
//	for(int i = 1; i <= n; i++)
//		for(int j = 1; j <= n; j++)
//			cout << dis[i][j] << " \n"[j == n];
	
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		long long ans = inf;
		if(x == y)
		{
			cout << 0 << endl;
			continue;
		}
		
		for(int i = 1; i <= num[x]; i++)
			for(int j = 1; j <= num[y]; j++)
			{
				int t1 = a[x][i], t2 = a[y][j];
//				cout << i << ' ' << t1 << endl;
//				cout << j << ' ' << t2 << endl;
//				cout << w[x] + w[y] << ' ' << t[x][i] << ' ' <<  t[y][j] << endl << endl;
				ans = min(ans, dis[t1][t2] + w[x] + w[y] + t[x][i] + t[y][j]);
			}
		cout << ans << endl;
		
	}
}

/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3



*/
