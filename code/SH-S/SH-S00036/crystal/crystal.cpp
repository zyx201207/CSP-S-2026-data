#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
long long a[MAXN], sum[MAXN];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	long long m;
	cin >> n >> m;
	unordered_map<long long, int> mp;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
		++mp[a[i]];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i)
		sum[i] = a[i] + sum[i - 1];
	long long last;
	int ans = 0;
	for (int i = 1; i <= n; ++i){
		if (a[i] == last || i == 1)
			continue;
		int l = 1, r = i - 1;
		while (l <= r){
			int mid = (l + r) >> 1;
			if (a[i] * (i - mid) - (sum[i - 1] - sum[mid - 1]) <= m){
				ans = max(ans, i - mid + mp[a[i]]);
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		last = a[i];
	}
	cout << ans;
}
