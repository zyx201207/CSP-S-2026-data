#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll n, num, cnt, l, r, ans;
char c;
struct node {
	ll num;
	int kind;
}a[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> num >> c;
		a[++cnt] = node{num, c - 'a' + 1};
	}
	l = 1, r = n;
	while(l < r) {
		if(a[l].kind != a[r].kind) {
			ans += min(a[l].num, a[r].num);
//			cout << ans;
		}
		if(a[r].num == a[l].num) {
			l++;
			r--;
		}
		else if(a[l].num < a[r].num) {
			a[r].num -= a[l].num;
			l++;
		}
		else {
			a[l].num -= a[r].num;
			r--;
//			cout << a[l].num;
		}
//		cout << l << " " << r  << " ans: " << ans << "\n";
	}
	cout << ans;
	return 0;
} 
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
