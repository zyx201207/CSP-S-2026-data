#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, m;
int a[N];
map<int, int> mp;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		stack<int> st;
		int len = 0, s[N];
		for (int j = i; j <= n; j++) {
			bool ok = false, f = false;
			memset(s, 0, sizeof(s));
			len = 0;
			st.push(a[j]);
			while (!st.empty()) {
				if (!f) {
					len++;
					s[len] += st.top();
					st.pop();
					f = true;
				}
				else {
					len++;
					s[len] += st.top();
					if (st.top() == a[j]) {
						ok = true;
						break;
					}
					else st.pop();
				}
			
			}
			if (!ok) {
				for (int k = len; k >= 1; k--) {
					st.push(s[k]);
				}
			}
		}
		while (!st.empty()) {
			mp[st.top()]++;
			st.pop();
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << mp[i] << ' ';
	}
	return 0;
}
