#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2000007;
int C, T;
int n, d;
int a[N];
struct Bck {
	int l, r;
};
int nm, ans;
Bck inf[N];
int lb[N], rb[N];
int lm[N], rm[N];

void test() {
	cin >> n >> d;
	for(int i=1; i<=n; i++)	cin >> a[i];
	int r = 0;
	nm = 0;
	for(int i=1; i<=n; i++) lb[i] = 0, rb[i] = 0;
	for(int i=1; i<=n; i++) {
		while(r + 1 <= n and a[r+1] - a[i] <= d) r += 1;
		if(r > inf[nm].r) nm += 1, inf[nm].l = i, inf[nm].r = r, lb[i] = nm, rb[r] = nm;
	}
//	cout << nm << endl;
	for(int i=1; i<=nm; i++) {
		lm[i] = inf[i+1].l - inf[i].l;
		if(rb[inf[i].l] != 0) lm[i] += lm[rb[inf[i].l]];
	}
//	for(int i=1; i<=nm; i++) cout << lm[i] << ' ';
//	cout << endl;
	for(int i=nm; i>=1; i--) {
		rm[i] = inf[i].r - inf[i-1].r;
		if(lb[inf[i].r] != 0) rm[i] += rm[lb[inf[i].r]];
	}
	ans = 0;
	for(int i=1; i<=nm-1; i++) {
		int l = inf[i].l, r = inf[i].r;
		if(r-1 <= 0 or lb[r-1] == 0 or inf[lb[r-1]].r == r-1) continue;
		int j = lb[r-1];
//		cout << i << ' ' << j << endl;
		ans += lm[i] * rm[j];
	}
	cout << ans << endl;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> C >> T;
	while(T--) test();
	return 0;
}
