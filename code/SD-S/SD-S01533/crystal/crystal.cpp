#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 101;

long long n, m;
long long sum[N];
long long ans, num;

long long pos;
priority_queue <long long, vector <long long>, greater<long long> > q1;
priority_queue <long long, vector <long long>, greater<long long> > q2;

int main() {
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for (long long i = 1; i <= n; i++) {
		long long a;
		cin >> a;
		q1.push(a);
	}
	
	while (!q1.empty()) {
		pos++;
		long long x = q1.top();
		sum[pos] = sum[pos - 1] + x;
		q1.pop();
		q2.push(x);
		long long need = x * (pos - num - 1) - (sum[pos - 1] - sum[num]);
		while (need > m) {
			long long y = q2.top();
			q2.pop();
			need -= (x - y);
			num++;
		}
		ans = max(ans, pos - num);
	}
	cout << ans;
	
	
	return 0;
}
