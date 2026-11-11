#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	unsigned long long m;
	cin >> n >> m;
	vector<int> a(n + 1, 0);
	vector<__int128>b(n +1, 0);
	vector<__int128> sum1(n + 1, 0), sum2(n + 1, 0);
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a.begin() + 1, a.end());
	// priority_queue<int, vector<int>, greater<int>> b;
	for (int i = 2; i <= n; i++){
		b[i - 1] = a[i] - a[i - 1];
		sum1[i - 1] = b[i - 1] * (i - 1);
	}
	for (int i = 1; i < n; i++){
		sum1[i] = sum1[i - 1] + sum1[i];
		sum2[i] = sum2[i - 1] + b[i];
	}
	auto check = [&](int x, int l)->bool{
		__int128 s1 = sum1[x] - sum1[l - 1];
		__int128 s2 = sum2[x] - sum2[l - 1];
		__int128 s3 = s1 - (l - 1) *  s2;
		// cout << l << ' ' << x << ' ' << s3 << endl;
		return (s3 <= m);
	};
	// cout << check(3, 1) << endl;
	int ans = 1;
	for (int i = 1; i < n; i++){
		int L = i, R = n - 1;
		while (L <= R){
			int mid = (L + R) / 2;
			// cout << L << ' ' << R << ' ' << mid << ":" << endl;
			if (check(mid, i)){
				ans = max(ans, mid - i + 2);
				// cout << "Right\n";
				L = mid + 1;
			} else R = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
