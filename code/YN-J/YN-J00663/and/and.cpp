#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n, m;
int a[100005];
long long cnt[100005];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int l = 0, cn = 1;
	for (int i = 0; i < n; ++i) {
		int sum = a[i];
		for (int j = i + 1; j < n; j ++) {
			cn++;
			sum = sum & a[j];
			if (cn % m == 0) {
				cnt[l] = sum;
				l++;
				sum = a[i];
				cn = 1;
			}
		}
	}
	sort(cnt, cnt + l, cmp);
	cout << cnt[0] << endl;
	return 0;
}