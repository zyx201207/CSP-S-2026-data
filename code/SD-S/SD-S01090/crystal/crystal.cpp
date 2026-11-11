#include<bits/stdc++.h>
#define endl '\n'
//#define MSOD

using namespace std;
using ll = long long;

const int N = 5e5 + 5;

int n;
ll m;

ll a[N], b[N];

void TEST() {
	cin>>n>>m;
	for(int i = 1 ; i <= n ; i ++) cin>>a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1 ; i <= n ; i ++) b[i] = a[i] + b[i - 1];
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++) {
		int L = 1, R = i, mx = 1;
		while(L <= R) {
			int mid = L + R >> 1;
			if(a[i] * (i - mid + 1) - (b[i] - b[mid - 1]) <= m) mx = i - mid + 1, R = mid - 1;
			else L = mid + 1;
		}
		ans = max(ans, mx);
	}
	cout<<ans;
	return;
}

signed main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int TC = 1;
#ifdef MSOD
	cin>>TC;
#endif
	while(TC --) TEST();
	return 0;
}
