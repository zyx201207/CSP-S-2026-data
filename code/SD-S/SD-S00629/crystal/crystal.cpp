#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 5e5 + 15;
int n, m;
long long res, a[MAXN], d[MAXN];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		d[i] = a[i] - a[i - 1];
	res = 0;
	for (int i = 1; i <= n; i++){
		if (m >= d[i] * (i - 1)){
			m -= d[i] * (i - 1);
			res++;
		}
		else
			break;
	}
	cout << res;
	return 0;
}

