#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define int long long

struct node {
	int va;
	char c;
} a[N];
int n, cnt;
int b[N], d[N];
char h[N], g[N];
string s = "", t = "";

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int l = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].va >> a[i].c;
		l += a[i].va;
	}
	int ans = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		//	if (sum + a[i].va <= l / 2) {
		for (int j = 0; j < a[i].va; j++) {
			s += a[i].c;
		}
		//	} else {
//			if (l % 2 == 1) {
//				if (sum + a[i].va == l / 2 + 1) {
//					for (int j = 0; j < a[i].va; j++) {
//						s += a[i].c;
//					}
//				} else {
//					for (int j = 0; j < a[i].va - (sum + a[i] - (l / 2 + 1)); j++) {
//						s += a[i].c;
//					}
//				}
//			} else {
//				for (int j = 0; j < a[i].va - (sum + a[i].va - l /2 );j++){
//			      s+=a[i].c;
//				}
//				break;
//		}
	}
	for (int i = 0; i < l / 2; i++) {
		if (s[i] != s[l - i])
			ans++;
	}
	cout << ans;
	return 0;
}