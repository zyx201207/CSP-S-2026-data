#include<bits/stdc++.h>
using namespace std;

int n, m;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int a[N];
int ans[M];
int used[M];
stack<int> st;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	memset(used, 0, sizeof(used));
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; ++j) {
			if(used[a[j]]) { // 用过这个花色，要管家 
				while(!st.empty()) {
					if(st.top() == a[j])
						break;
					used[st.top()] = 0;
					st.pop();
				}
			} else {
				used[a[j]] = 1;
				st.push(a[j]);
			}
		}
		while(!st.empty()) {
			ans[st.top()]++;
			st.pop();
		}
		memset(used, 0, sizeof(used));
	}
	for(int i = 1; i <= m; ++i) {
		cout << ans[i] << " "; 
	} 
	return 0;
}
