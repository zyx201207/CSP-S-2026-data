#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
struct node {
	int x;
	string s;
};
int n;
string S;
node a[N];
int ans;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i].x;
		cin >> a[i].s;
	}
	int l = 1, r = n;
	while(l < r) {
		int t = min(a[l].x, a[r].x);
		a[l].x -= t;
		a[r].x -= t;
		if(a[l].s != a[r].s) {
			ans += t;
		}
		if(a[l].x == 0) {
			l ++;
		}
		if(a[r].x == 0) {
			r --;
		}
	}
	cout << ans;
}
