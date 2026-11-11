#include<bits/stdc++.h>
#define endl '\n'
#define udmap unordered_map
#define udset unordered_set
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;

const int N = 5e5 + 10;
int n, m;
int a[N], ans[N];

void solve() {
	for(int i = 1; i <= n; i++) {
		vector<int> cnt(m + 1, 0);
		stack<int> stk;
		for(int j = i; j <= n; j++) {
			if(!cnt[a[j]]) {
				stk.push(a[j]);
				cnt[a[j]]++;
			} else {
				while(stk.top() != a[j]) {
					cnt[stk.top()]--;
					stk.pop();
				}
			}
		}
		for(int j = 1; j <= m; j++) {
			if(cnt[j]) {
				ans[j]++;
			}
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	bool A = true;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i - 1] > a[i]) A = false;
	}
	if(A) {
		for(int i = 1; i <= n; i++) {
			ans[a[i]] = i;
		}
		for(int i = 1; i <= m; i++) {
			cout << ans[i] << " ";
		}
	} else {
		solve();
	}
	return 0;
} 
