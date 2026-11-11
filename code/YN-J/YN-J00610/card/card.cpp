#include <bits/stdc++.h>
using namespace std;
int a[500005];
int s[300005];
int sum[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	memset(s, 0, sizeof(s));
	memset(sum, 0, sizeof(sum));
	int n, m;
	cin >> n >> m;
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[a[i]] += 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[a[j]] == 1)
				sum[a[j]]++;
		}
		s[a[i]]--;
	}
	for (int i = 1; i <= m; i++) {
		cout << sum[i] << " ";
	}
	return 0;
}