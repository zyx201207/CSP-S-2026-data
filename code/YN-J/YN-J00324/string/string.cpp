#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5 + 10;
int n;
char C[MAXN];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int tot = 0;
	for(int i = 1; i <= n; i++)
	{
		int cnt;
		char c;
		cin >> cnt >> c;
		for(int j = 1; j <= cnt; j++)
		{
			C[++tot] = c;
		}
	}
	int res = 0;
	for(int i = 1; i <= (tot / 2); i++)
	{
		if(C[i] != C[tot - i + 1]) res++;
	}
	cout << res;
	return 0;
}