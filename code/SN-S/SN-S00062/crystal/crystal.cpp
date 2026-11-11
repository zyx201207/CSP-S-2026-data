#include <bits/stdc++.h>
using namespace std; 
const int maxn = 500010;
long long n, m;
long long arr[maxn], a[maxn];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++){
		arr[i] = (a[i] - a[i - 1]) * (i - 1) + arr[i - 1];
	}
	long long ans = 0;
	for (int i = 1; i <= n; i ++){
		long long l = i, r = n, mid;
		while (l <= r){
			mid = (l + r) / 2;
			if (arr[mid] - arr[i - 1] - (a[mid] - a[i - 1]) * (i - 1) <= m) l = mid + 1;
			else r = mid - 1;
		}
		ans = max(ans, r - i + 1);
	}
	cout << ans;
	return 0;
}
