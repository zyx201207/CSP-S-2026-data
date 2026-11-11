# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 5e5 + 5;
ll n, m, a[N], ans[N], tmp[N];
bool f[N];
stack <ll> st;

int main () {
	
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i ++) cin >> a[i];
	if (n <= 5000 && m <= 3000) {
		for (ll i = 1; i <= n; i ++) {
			// 第 i 局
			memset (f, 0, sizeof (f));
			while (! st.empty ()) st.pop ();
			for (ll j = i; j <= n; j ++) {
				if (! f[a[j]]) {
					st.push (a[j]);
					f[a[j]] = 1;
				} else {
					while (! st.empty () && st.top () != a[j]) 
						f[st.top ()] = 0, st.pop ();
					st.pop ();
					st.push (a[j]); 
				}
			} 
			for (ll i = 1; i <= m; i ++)
				if (f[i]) ans[i] ++;
		}
		for (ll i = 1; i <= m; i ++) cout << ans[i] << " ";
	} 
	else {
		for (ll i = 1; i <= n; i ++) {
			// 第 n - i + 1 局
			if (f[a[n - i + 1]]) {
				while (! st.empty () && st.top () != a[n - i + 1])
					f[st.top ()] = 0, st.pop (), tmp[st.top () --];
				st.pop ();
				tmp[a[n - i + 1]] --;
			}
			st.push (a[n - i + 1]);
			f[a[n - i + 1]] = 1;
			tmp[a[n - i + 1]] ++;
			for (ll j = 1; j <= m; j ++)
				if (f[j]) ans[j] ++;
		}
		for (ll i = 1; i <= m; i ++) cout << ans[i] << " ";
	}
	
	return 0;
}
