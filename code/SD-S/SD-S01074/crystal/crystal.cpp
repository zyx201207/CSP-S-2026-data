#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 10;

int n;
long long m;
long long a[maxn], b[maxn];

bool t(int l, int r)
{
	long long t = (r - l + 1) * a[r] - (b[r] - b[l - 1]);
	return t <= m;
}

bool check(int len)
{
	for(int i = 1; i + len - 1 <= n; i++)
		if(t(i, i + len - 1)) return true;
	return false;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	for(int i = 1; i <= n; i++)
		b[i] = b[i - 1] + a[i];
	int l = 1, r = n, mid;
	while(l < r)
	{
		mid = ((l + r) >> 1) + 1;
		if(check(mid))
			l = mid;
		else
			r = mid - 1;
	}
	cout << l << endl;
}
/*

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
