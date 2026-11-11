#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int n, m;
long long mx;
long long a[N];
long long tb[30][N];
vector<int> num[30];
long long cnt[30];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	long long ans = (1<<30)-1;
	for(int i = 1; i <= n; i++) {
		ans = ans & a[i];
	}
	if(m == 1) cout << mx;
	else if(m == n) cout << ans;
	return 0;
}