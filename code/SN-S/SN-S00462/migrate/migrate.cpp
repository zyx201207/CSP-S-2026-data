// SN-00462 µ­³şÜ² ¸¨ÂÖÖĞÑ§ 
#include <bits/stdc++.h>
#define il inline
#define int long long
#define vc vector
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int N = 5005, M = 2e6 + 5;
int TTT = 1, n, m, k, c, a[M], t[N][N], s[N][N], d[N][N];

void mian()
{
	cin >> n >> m;
	bool opA = 1;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 2; i <= n; i++) opA &= (a[i] - a[i - 1] == a[2] - a[1]);
	
	if(opA)
	{
		int d = a[2] - a[1], t = m / d;
		if(t <= 1 || t >= n) {cout << "0\n"; return;}
		int i = t + t - 1;
		cout << n - i << "\n";
		return;
	}	

	for(int i = 1; i <= n; i++)
	{
		s[i][i] = t[i][i] = 1, d[i][i] = 0; int nw = 1;
		bool f = 0;
		for(int j = i + 1; j <= n; j++)
		{
			if(f) {s[i][j] = t[i][j] = 0; continue;}
			int l = i, r = j - 1;
			while(l <= r)
			{
				int mid = (l + r) / 2;
				if(a[j] - a[mid] <= m) r = mid - 1;
				else l = mid + 1;
			}
			if(l == j) {f = 1; continue;}
			d[i][j] = d[i][l] + 1;
			if(d[i][j] != d[i][j - 1]) nw = s[i][j - 1];
			t[i][j] = nw - s[i][l - 1];
			s[i][j] = s[i][j - 1] + t[i][j];
//			cout << i << " " << j << " " <<l << " " << t[i][j] << " " << m << " " << a[j] - a[l] <<  "fdsa\n"; 
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(t[i][j] == 2) ans++;
	cout << ans << "\n";
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> c >> TTT;
	while(TTT--) mian();
	return 0;
}
