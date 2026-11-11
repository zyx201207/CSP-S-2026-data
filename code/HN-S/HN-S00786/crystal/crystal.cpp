#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], lg[500005];
__int128 s[500005], st[500005][20];
bool check(int x){
	int len = lg[x];
	for(int l = 1, r = x; r <= n; l++, r++){
		__int128 maxn = max(st[l][len], st[r - (1 << len) + 1][len]);
		__int128 sum = s[r] - s[l - 1];
		if(maxn * x - sum <= m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
		st[i][0] = a[i];
	}
	for(int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
	for(int len = 1; len <= lg[n]; len++){
		for(int i = 1; i + (1 << len) - 1 <= n; i++){
			st[i][len] = max(st[i][len - 1], st[i + (1 << len - 1)][len - 1]);
		}
	}
	int l = 1, r = n;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l;
	return 0;
} 
