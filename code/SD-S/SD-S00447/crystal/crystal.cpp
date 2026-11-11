#include <bits/stdc++.h>

#define int long long 

#define PII pair<int, int>

#define mkp make_pair

using namespace std;

const int N = 5e5 + 10;

int n, m;
int qzh[N];
int a[N];
int ans;

void readin() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
}

void preprocess() {
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		qzh[i] = qzh[i - 1] + a[i];
	}
}

bool check(int val, int pla) {
	//calc_qzh
	int sum_l = val;
	int sum_r = pla - 1;
	int nowsum = qzh[sum_r] - qzh[sum_l - 1];
	int gssum = (sum_r - sum_l + 1) * a[pla];
	int chn_num = gssum - nowsum;
	if (chn_num <= m) return true;
	return false;
}

int Binsearch(int pla) {
	int l = 1, r = pla - 1;
	int mid, ans;
	mid = ans = -1;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid, pla)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return ans;
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		int rs = Binsearch(i);
		int usednum = i - rs;
		ans = max(ans, usednum + 1);	
	}	
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	readin();
	preprocess();
	solve();
	cout << ans << "\n";
	return 0;
}
