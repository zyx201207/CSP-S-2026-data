#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 2e5 + 5;
long long nums[N][2];

long long solve() {
	long long cnt = 0;
	for (int i = 0; i < n / 2; ++i) {
		int j = n - i - 1;
		if (nums[i][1] != nums[j][1]) {
			cnt += min(nums[i][0], nums[j][0]);
		}
		if (nums[i][0] < nums[j][0]) {
			if (nums[i + 1][1] != nums[j][1]) {
				cnt += nums[j][0] - nums[i][0];
			}
			nums[i+1][0] -= nums[j][0] - nums[i][0];
		} else if (nums[i][0] >= nums[j][0]){
			if (nums[i][1] != nums[j + 1][1]) {
				cnt += nums[i][0] - nums[j][0];
			}
			nums[j+1][0] -= nums[i][0] - nums[j][0];
		}
	}
	return cnt;
}

int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(false);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		char c;
		cin >> a >> c;
		nums[i][0] = a;
		nums[i][1] = c;
	}
	
	cout << solve() << endl;
	
	return 0;
}
