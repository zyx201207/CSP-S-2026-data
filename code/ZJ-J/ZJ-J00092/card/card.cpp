#include <bits/stdc++.h>
using namespace std;
#define IOS cin.tie(nullptr) -> sync_with_stdio(false)
const int N = 5e5 + 10;
int n, m, a[N], st[N], lastPos[N], cnt[N];
int tt = 0;
int main() { IOS;
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	
	for(int i = n; i >= 1; --i) {
		if(lastPos[a[i]]) {
			tt = lastPos[a[i]];
		} else {
			st[++tt] = a[i];
			lastPos[a[i]] = tt;
		}
		for(int j = 1; j <= tt; j++) {
			cnt[st[j]]++;
		}
	}
	
	for(int i = 1; i <= m; i++) {
		cout << cnt[i] << ' ';
	}
	return 0;
}