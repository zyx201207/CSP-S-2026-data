#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 5e5 + 10;

ll n, m, a[maxn], pre[maxn];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] + a[i];
	}
	
	for(int i = 1; i <= n; i++){
		if(a[i] * (i - 1) > m + pre[i]){
			cout << i - 1;
			return 0;
		}
	}
	return 0;
}

