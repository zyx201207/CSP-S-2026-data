#include <bits/stdc++.h> 
#define int long long

using namespace std;

const int N = 510;
const int M = 5e5 + 100;

struct edge
{
	int x, v;
};

int c, n, m, d, q;

int w[M];
int k[N];

int dp[N][N];
vector<pair<int, int> > t2[M]; 


void read(int &x) 
{
	x = 0;
	int res = 1;
	char c = getchar();
	while (!(c >= '0' && c <= '9' || c == '-')) c = getchar();
	if (c == '-') res = -1, c = getchar();
	while (c >= '0' && c <= '9') 
	{
		x = x * 10 + c - '0';
		c = getchar(); 
	}
	x = x * res; 
}

char res[40];
void write(int x) 
{
	int cnt = -1;
	if (x == 0) 
	{
		putchar('0');
		puts("");
		return ;
	}
	bool flag = true;
	if (x < 0) flag = false, x = -x;
	
	while (x) 
	{
		res[++ cnt] = x % 10 + '0';
		x /= 10;
	}
	
	if (flag == false) res[++ cnt] = '-';
	for (int i = cnt; i >= 0; i--) putchar(res[i]);
	puts("");
	
}

signed main () 
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

//	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	read(c), read(n), read(m), read(d), read(q);
	
	for (int i = 1; i <= m; ++i) read(w[i]);
	
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) dp[i][j] = LLONG_MAX / 3; 
	
	for (int i = 1; i <= n; ++i) 
	{
//		scanf("%lld", &k[i]);
		read(k[i]);
		for (int j = 1; j <= k[i]; ++j) 
		{
			int a, t;
//			scanf("%lld%lld", &a, &t);
			read(a), read(t);
//			dist[i][a] = t;
			if (!t2[a].empty()) 
			{
				for (auto k : t2[a]) 
				{
					int w = k.second + t;
					if (dp[i][k.first] > k.second + t) dp[i][k.first] = dp[k.first][i] = w;
				}
			} 
			t2[a].push_back({i, t});
		}
	}
	
	for (int i = 1; i <= n; ++i) dp[i][i] = 0;
	
	for (int k = 1; k <= n; ++k) 
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j) 
			{
				if (dp[i][k] + dp[k][j] < dp[i][j]) dp[i][j] = dp[j][i] = dp[i][k] + dp[k][j];
			} 	
		} 
	}
	
	for (int i = 1; i <= q; ++i) 
	{
		int x, y;
//		scanf("%lld%lld", &x, &y);
		read(x), read(y);
		int ans = LLONG_MAX;
		for (auto j : t2[x]) 
		{
			for (auto k : t2[y]) 
			{
				int w = j.second + dp[j.first][k.first] + k.second;
				if (w < ans) ans = w;
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
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
