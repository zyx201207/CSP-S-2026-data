#include <bits/stdc++.h>
#define int long long
using namespace std;

#define FOR(x, y, z) for(int (x) = (y); (x) <= (z); (x)++)
#define ROF(x, y, z) for(int (x) = (y); (x) >= (z); (x)--)s
#define mp make_pair
#define pb push_back

const int N = 2e6 + 10;
int n, d, a[N], ans, nxt[N], L1[N], L2[N], L0[N];
int red[N], yel[N], f[N][2];

void solve(){
	FOR(i, 0, n + 1) a[i] = nxt[i] = red[i] = yel[i] = f[i][0] = f[i][1] = L1[i] = L2[i] = L0[i] = 0;
	ans = 0;

	cin >> n >> d;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n){
		if(i == n || a[i + 1] > a[i] + d) nxt[i] = n + 1;
		else nxt[i] = upper_bound(a + i, a + 1 + n, a[i] + d) - a - 1;
	}
	nxt[n + 1] = n + 1;

	FOR(A, 1, n){
		int B = nxt[A], C = nxt[B], D = nxt[C];
		if(D == n + 1){red[A] = 1; continue;}
		if(B - 1 > A && C - 1 > B && a[C - 1] - a[B - 1] <= d && a[D] - a[C - 1] <= d){red[A] = 1; continue;}
		int cnt = 0;
		if(B - 1 > A && a[C] - a[B - 1] <= d) cnt++;
		if(B - 2 > A && a[C] - a[B - 2] <= d) cnt++;
		if(cnt >= 2) red[A] = 1;
		else if(cnt == 1) yel[A] = 1;
	}

	FOR(i, 1, n){
		f[i][0]++;
		if(nxt[i] != n + 1 && !red[i]){
			if(yel[i]) f[nxt[i]][1] += f[i][0];
			else f[nxt[i]][1] += f[i][1], f[nxt[i]][0] += f[i][0];
		}
	}

	a[0] = -5e18;
	L0[0] = 0, L1[0] = 0, L2[0] = 0;
	FOR(A, 1, n){
		L0[A] = L0[A - 1], L1[A] = L1[A - 1], L2[A] = L2[A - 1];
		int B = nxt[A];
		if(B == n + 1) continue;
		while(L2[A] < n && L2[A] < nxt[B] && a[L2[A] + 1] - a[B] <= d) L2[A]++;
		if(B - 1 > A) while(L1[A] < L2[A] && a[L1[A] + 1] - a[B - 1] <= d) L1[A]++;
		if(B - 2 > A) while(L0[A] < L1[A] && a[L0[A] + 1] - a[B - 2] <= d) L0[A]++;
		ans += max(0ll, min(L2[A], L1[A]) - max(B, L0[A]));
	}

	FOR(A, 1, n){
		int B = nxt[A], C = nxt[B];
		if(B == n + 1 || C == n + 1) continue;
		int cnt = 0;
		if(B - 1 > A && a[C] - a[B - 1] <= d) cnt++;
		if(B - 2 > A && a[C] - a[B - 2] <= d) cnt++;

		int R = min(nxt[C], L2[B]);
		int L = max(C + 1, L0[B] + 1); if(B - 1 > A && C - 1 > B && a[C - 1] - a[B - 1] <= d) L = L1[B] + 1;
		if(cnt == 1) ans += f[A][0] * max(0ll, R - max(L1[B] + 1, L) + 1);
		else{
			ans += f[A][0] * max(0ll, min(R, L1[B]) - L + 1);
			ans += f[A][1] * max(0ll, R - max(L1[B] + 1, L) + 1);
		}
	}

	cout << ans << "\n";
	return ;
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int c, t; cin >> c >> t;
	while(t--) solve();
	return 0;
}