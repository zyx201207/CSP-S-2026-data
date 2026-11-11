#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], ans1, ans2, flag;
long long min_dis = LLONG_MAX, max_sum = 0, min_dis_id, max_sum_id;
unordered_map<long long, long long> mp;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	int sum = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] != a[i - 1]) {
			mp[a[i - 1]] = sum;
			if (min_dis > abs(a[i] - a[i - 1])) {
				min_dis = abs(a[i] - a[i - 1]);
				min_dis_id = i;
			}
			if (max_sum < sum) {
				max_sum = sum;
				max_sum_id = i - sum;
			}
			if (max_sum == sum && i - sum > 1 && max_sum_id > 1
			        && a[i - sum] - a[i - sum - 1] < a[max_sum_id] - a[max_sum_id - 1]) {
				max_sum = sum;
				max_sum_id = i - sum;
			}
			sum = 1;
			continue;
		}
		sum++;
	}
	if (max_sum < sum) {
		max_sum = sum;
		max_sum_id = n - sum + 1;
	}
	if (max_sum == sum && n - sum + 1 > 1 && max_sum_id > 1
	        && a[n - sum + 1] - a[n - sum] < a[max_sum_id] - a[max_sum_id - 1]) {
		max_sum = sum;
		max_sum_id = n - sum + 1;
	}
	mp[a[n]] = sum;
	for (int i = 2; i <= n; i++) {
		if (a[i] != a[i - 1]) {
			if (min_dis == abs(a[i] - a[i - 1]) && mp[a[i]] > mp[a[min_dis_id]]) {
				min_dis = abs(a[i] - a[i - 1]);
				min_dis_id = i;
			}
		}
	}
	if (m < min_dis) {
		cout << max_sum;
		return 0;
	}
	long long now_sum = mp[min_dis_id] + 1, now_num = a[min_dis_id];
	long long i = min_dis_id + mp[a[min_dis_id]], j = min_dis_id - 2, mm = m;
	mm -= min_dis;
	while ((i <= n || j >= 1)) {
		min_dis = LLONG_MAX, flag = LLONG_MIN;
		if (now_num - a[j] < (a[i] - now_num) * now_sum && j >= 1) {
			if (j >= 1) {
				min_dis = now_num - a[j];
				j--;
			}
		} else if (now_num - a[j] == (a[i] - now_num) * now_sum && ( now_num - a[j]) * mp[a[j]] < (a[i] - now_num) * now_sum
		           && j >= 1) {
			if (j >= 1) {
				min_dis = now_num - a[j];
				j--;
			}
		} else {
			if (i <= n) {
				min_dis = (a[i] - now_num) * now_sum;
				now_num = a[i];
				flag = a[i];
				i += mp[a[i]];
			}
		}
		if (mm < min_dis)
			break;
		now_sum += (flag != LLONG_MIN ? mp[flag] : 1);
		mm -= min_dis;
	}
	ans1 = now_sum;
	now_sum = max_sum, now_num = a[max_sum_id];
	i = max_sum_id + max_sum, j = max_sum_id - 1, mm = m;
	while ((i <= n || j >= 1)) {
		min_dis = LLONG_MAX, flag = LLONG_MIN;
		if (now_num - a[j] < (a[i] - now_num) * now_sum && j >= 1) {
			if (j >= 1) {
				min_dis = now_num - a[j];
				j--;
			}
		} else if (now_num - a[j] == (a[i] - now_num) * now_sum && ( now_num - a[j]) * mp[a[j]] < (a[i] - now_num) * now_sum
		           && j >= 1) {
			if (j >= 1) {
				min_dis = now_num - a[j];
				j--;
			}
		} else {
			if (i <= n) {
				min_dis = (a[i] - now_num) * now_sum;
				now_num = a[i];
				flag = a[i];
				i += mp[a[i]];
			}
		}
		if (mm < min_dis)
			break;
		now_sum += (flag != LLONG_MIN ? mp[flag] : 1);
		mm -= min_dis;
	}
	ans2 = now_sum;
	cout << max(ans1, ans2);
	return 0;
}