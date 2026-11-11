// Yang Mofei
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<pair<int, char>> vec;
unordered_set<int> covered;
int total;

void insert(int i) {
	if (covered.find(total + 1 - i) != covered.end()) {
		return;
	}
	covered.insert(i);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	vec.resize(n + 1, {0, ' '});
	for (int i = 1; i <= n; i++) {
		cin >> vec[i].first >> vec[i].second;
	}

	vector<int> sum(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + vec[i].first;
	}
	total = sum[n];

	for (int i = 1; i <= n; i++) {
		insert(sum[i - 1] + 1);
		insert(sum[i]);
	}
	insert(1);

	int mid = (total >> 1) + 1;
	vector<int> cover;
	for (auto num : covered) {
		if (num >= mid) {
			num = total + 1 - num;
		}
		cover.push_back(num);
	}
	cover.push_back(mid);
	sort(cover.begin(), cover.end());
//	cout << total << endl;
//	for (int i = 0; i < cover.size() - 1; i++) {
//		cout << cover[i] << " ";
//	}
	int ans = 0;
	for (int i = 0; i < cover.size() - 1; i++) {
		int counterpart = total + 1 - cover[i];
		auto it1 = lower_bound(sum.begin(), sum.end(), cover[i]);
		auto it2 = lower_bound(sum.begin(), sum.end(),
		                       counterpart);
		int ind1 = it1 - sum.begin();
		int ind2 = it2 - sum.begin();
		if (vec[ind1].second != vec[ind2].second) {
			ans += cover[i + 1] - cover[i];
		}
	}

	cout << ans << endl;
	return 0;
}