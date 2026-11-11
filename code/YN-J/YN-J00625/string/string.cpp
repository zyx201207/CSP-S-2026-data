#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

struct node {
	int num;
	char c;
};
node a[N];
vector<node>vt;
int n;

int ish(vector<node>a) {
	vector<node>b;
	for (int i = a.size() - 1; i >= 0; i--) {
		b.push_back(a[i]);
	}
	for (int i = 0; i < a.size(); i++) {
		if ((a[i] .num != b[i].num) || (a[i].c != b[i].c))
			return 0;
	}
	return 1;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	a[0].num = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].num >> a[i].c;
	}
	int sum = 0;
	char tmp = a[1].c;
	for (int i = 1; i <= n; i++) {
		if (tmp != a[i].c) {
			vt.push_back({sum, tmp});
			sum = 0;
			tmp = a[i].c;
		}
		sum += a[i].num;

	}
	vt.push_back({sum, tmp});
	int vs = vt.size();
	int ans = 0;
	if (vs == 1) {
		cout << 0;
		return 0;
	}
	int r = vs - 1, l = 0;
	int cnt = 0;
	while (l < r) {
		if (vt[l].num == 0)
			l++;
		if (vt[r].num == 0)
			r--;
		if (vt[l].c == vt[r].c) {
			if (vt[l].num == vt[r].num) {
				l++, r--;
				continue;
			}
			if (vt[l].num > vt[r].num) {
				vt[l].num -= vt[r].num;
				r--;
			} else {
				vt[r].num -= vt[l].num;
				l++;
			}
		} else {
			cnt += min(vt[l].num, vt[r].num);

			if (vt[l].num > vt[r].num) {
				vt[l].num -= vt[r].num;
				r--;
			} else {
				vt[r].num -= vt[l].num;
				l++;
			}
			//cout << vt[l].c << vt[r].c << endl;
		}
		//if (r - l == 1) {
		//		cnt += min(vt[l].num, vt[r].num);
		//	}
	}
	cout << cnt;
	return 0;
}