#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, ans;
int a[N];
int diff[N];
deque<int> q;
signed main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0)->sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 2; i <= n; i++) {
		diff[i] = a[i] - a[i-1];
	}
	int tmp = 0;
	for(int i = 1; i <= n; i++) {
		tmp += q.size() * diff[i];
		while(!q.empty() && tmp > m) {
			tmp -= a[i] - a[q.front()];
			q.pop_front();
		}
		q.push_back(i);
		ans = max(ans,(int)q.size());
	}
	cout << ans;
	return 0;
}