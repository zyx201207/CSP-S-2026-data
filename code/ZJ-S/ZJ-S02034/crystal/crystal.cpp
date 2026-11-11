#include <bits/stdc++.h>
#define File(x) (freopen(x".in", "r", stdin), freopen(x".out", "w", stdout))
#define N 1000006
#define ll long long
using namespace std;

int n, m, ans;
ll a[N], b[N];

int main() {
	File("crystal"), ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for(int i=1 ; i<=n ; i++) cin >> a[i];
	sort(a+1, a+1+n);
	for(int i=1 ; i<=n ; i++) b[i] = b[i-1] + a[i];
	for(int i=1 ; i<=n ; i++) {
		int bl = 1, br = i, ba = i;
		while(bl <= br) {
			int bm = (bl+br) >> 1;
			if(a[i] * (i-bm+1) - (b[i]-b[bm-1]) <= m) ba = bm, br = bm-1;
			else bl = bm+1;
		}
		ans = max(ans, i-ba+1);
	} printf("%d\n", ans);
	return 0;
}