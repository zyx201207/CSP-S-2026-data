#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

//const int MAXN = ;

void solve() {
	int n, m; cin >> n >> m;
	
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	vector<int> _begin(m + 1), cnt(m + 1, 0);
	for (int i = 1; i <= m; i++) {
		_begin[i] = i;
	}
	
	for (int i = 1; i <= n; i++) {
		vector<int> now(m + 1);
		int len = 0;
		for (int j = i; j <= n; j++) {
			auto it = find(now.begin() + 1, now.begin() + len, a[j]);
			if (it == now.begin() + len) {
				now[len + 1] = a[j];
				len++;
			} else {
				len = it - now.begin();
				now[len] = a[j];
			}
		}
		
		for (int i = 1; i <= len; i++) {
			cnt[now[i]]++;
		}
	}
	
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << " ";
	}
	
	cout << endl;
	return ;
}

int main () {
	ios::sync_with_stdio();
	cin.tie(nullptr);
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int T = 1; //cin >> T;
	while (T--) {
		solve();
	}
	
	return 0;
}

