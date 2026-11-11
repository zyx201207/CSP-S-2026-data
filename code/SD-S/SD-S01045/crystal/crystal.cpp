#include <bits/stdc++.h>
//#define int long long

using namespace std;

//object:
const int N = 5e5 + 50;
long long n, m;
long long nums[N], cha[N], sum[N];

//data structure:


//function:
bool cmp (long long a, long long b) {
	return a > b;
}

int main() {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> nums[i];
//		mp[nums[i]] ++;
	}
	sort (nums + 1, nums + n + 1);
//	int cnts = unique (nums + 1, nums + n + 1) - nums - 1;
//	for (int i = 1; i <= n; i ++) {
//		cnt[n - i + 1] = mp[nums[i]];
//	}
//	for (int i = 1; i <= n; i ++) {
//		cout << nums[n - i + 1] << ":" << cnt[i] << "\n";
//	}
	for (int i = 1; i <= n; i ++) {
		cha[n - i + 1] = nums[i + 1] - nums[i];
	}
	cha[1] = 0;
//	for (int i = 1; i <= n; i ++) {
//		cout << cha[i] << " ";
//	}
//	cout << "\n";
	
	for (int i = 1; i <= n; i ++) {
		sum[i] = sum[i - 1] + cha[i];
//		cout << sum[i] << " ";
	}
//	cout << "\n";
	//5 8 -3 -1 2 2 7
	long long r = 1, tmp = 0, ans = -1e18 - 50, cntp = 0;
//	sum[cnts] = sum[cnts - 1];
	for (int i = 1; i <= n; i ++) {
		if (i != 1) tmp -= (r - i + 1) * (sum[i] - sum[i - 1]);
		while (r <= n && tmp + sum[r] - sum[i] <= m) {
			tmp += sum[r] - sum[i];
			r ++;
		}
//		cout << i << " " << r << " " << cnt[i] << " ";
//		cout << tmp << " ";
		ans = max (ans, r - i);
//		cout << ans << "\n";
	}
	cout << ans << "\n";
	return 0;
}
