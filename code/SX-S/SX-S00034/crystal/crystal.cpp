#include <bits/stdc++.h>
using namespace std;
long long n, m, sum, cnt = 1, mmax;
long long a[500005];
long long f[500005];

inline bool cmp(long long x, long long y) {
	return x < y;
}

deque<long long> que;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	stable_sort(a + 1, a + n + 1, cmp);
	for (int i = 1 ; i <= n ; i++) {
		f[i] = a[i] - a[i - 1];
		//cout << f[i] << " ";
	}
	//cout << "\n";
	que.push_back(1);
	while (cnt <= n) {
		while (sum + f[cnt + 1] * (que.back() - que.front() + 1) <= m && cnt <= n) {
			cnt++;
			que.push_back(cnt);
			sum += f[cnt] * (que.back() - que.front());
			//cout << "1:" << sum << " " << cnt << "\n";
		}

		mmax = max(mmax, que.back() - que.front() + 1);

		sum -= a[que.back()] - a[que.front()];
		que.pop_front();


		//cout << "2:" << sum << "\n";


	}

	cout << mmax;



	return 0;
}
