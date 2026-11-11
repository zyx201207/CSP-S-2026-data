#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 5e5 + 10;
const LL INF = 1e18 + 10;
LL a[N], s[N], n, m; 

int main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) s[i] = s[i-1] + a[i];
	
	int l = 1, r = n;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		
		LL add = INF;
		for (int i = 1; i + mid - 1 <= n; ++i) {
			int j = i + mid - 1;
			add = min(add, a[j] * mid - (s[j] - s[i-1]));
		}
		
		if (add > m) r = mid - 1;
		else l = mid;
	}
	cout << l << "\n";
	return 0;
} 
