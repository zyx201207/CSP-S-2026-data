#include<bits/stdc++.h>
using namespace std;

int n, m;
const int N = 2e5 + 5;
int a[N];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	int l = 1, r = m;
	int maxn = 0;
	while(r <= n) {
		int tmp = a[l];
		for(int i = l + 1; i <= r; ++i)
			tmp = tmp & a[i];
		if(tmp >= maxn)
			maxn = tmp;
		l++, r++;
	}
	cout << maxn << "\n";
	return 0;
}
