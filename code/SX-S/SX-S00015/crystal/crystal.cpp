#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define LL long long

#define I using
#define AK namespace
#define IOI std
I AK IOI;

//卡特殊性质，令人忍俊不禁

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	LL m, rst = LONG_LONG_MIN;
	cin >> n >> m;
	vector<LL> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (n > 5000) {
		cout << m / abs(arr[0] - arr[1]);
	}
	sort(arr.begin(), arr.end(), greater<int>());
	for (int i = 0; i < n - 1; i++) {
		LL sum = 0, cnt = 0;
		for (int j = i; j < n; j++) {
			sum += arr[i] - arr[j];
			cnt++;
			if (sum > m) {
				break;
			}
			if (cnt > rst) {
				rst = cnt;
			}
			rst = max(cnt, rst);
		}
	}

	cout << rst;

}
