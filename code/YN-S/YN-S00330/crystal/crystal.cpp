#include <bits/stdc++.h>
using namespace std;
long long num[500100], cha[500100], he[500100];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		cha[i] = num[i] - num[i - 1];
		he[i] = cha[i] + he[i - 1];
	}
	sort(num + 1, num + n + 1);
	long long sum = 0, i = 1;
	while (m >= 0) {
		m -= he[i];
		i++;
		sum++;
	}
	cout << sum;
	return 0;
}
