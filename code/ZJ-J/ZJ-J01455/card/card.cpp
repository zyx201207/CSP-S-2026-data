#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

long long n, m, a[N];
long long cnt[N];
long long ans[N];

long long p[N];

void solveA() {
	for (long long i = 1; i < n; i++) {
		if (a[i] != a[i + 1]) {
			p[a[i]] = i;
		}
	}
	
	for (long long i = 1; i < m; i++)
		cout << p[i] << " ";
		
	cout << n << "\n";
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
		cin >> a[i];

	bool A = true;
	for (long long i = 1; i < n; i++) {
		if (a[i] > a[i + 1]) {
			A = false;
			break;
		}
	}

	if (A) {
		solveA();
		return 0;
	}

	for (long long i = 1; i <= n; i++) {
		for (long long i = 1; i <= m; i++)
			cnt[i] = 0;

		stack<long long> st;

		for (long long j = i; j <= n; j++) {
			if (cnt[a[j]] == 0) {
				st.push(a[j]);
				cnt[a[j]]++;
			} else {
				while (!st.empty()) {
					long long cur = st.top();
					st.pop();
					cnt[cur]--;
					if (cur == a[j]) break;
				}
				st.push(a[j]);
				cnt[a[j]]++;
			}
		}

		vector<long long> tmp(m + 1, 0);
		
		while (!st.empty()) {
			long long cur = st.top();
			tmp[cur] = 1;
			st.pop();
		}
			
		for (long long i = 1; i <= m; i++)
			ans[i] += tmp[i];
	}

	for (long long i = 1; i <= m; i++)
		cout << ans[i] << " ";
	cout << "\n";

	return 0;
}