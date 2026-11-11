#include<bits/stdc++.h>
using namespace std;
#define CLOSE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int n, m, a[500010], cnt[300010];
map<int, int> mp;
int main() {
	CLOSE
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	memset(cnt, 0, sizeof cnt);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		stack<int>st;
		for(int k = 1; k <= m; k++) {
			mp[k] = 0;
		}
		for(int j = i; j <= n; j++) {
			if(mp[a[j]] == 0) {
				mp[a[j]] = 1;
				st.push(a[j]);
			}
			else if(mp[a[j]] == 1){
				while(!st.empty() && st.top() != a[j]) {
					if(st.top() == a[j]) break;
					st.pop();
				}
			}
		}
		while(!st.empty()) {
			cnt[st.top()] += 1;
			st.pop();
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << cnt[i] << " " ;
	}
}
