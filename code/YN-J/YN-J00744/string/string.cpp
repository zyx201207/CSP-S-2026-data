#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll  S = 0;


struct aaa {
	int a;
	char c;
} s[1000000];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i].a >> s[i].c;
	}
	int r = n - 1;
	int l = 0;
	for (int i = 0; ; i++) {
		if (r == l) {
			cout << S ;
			return 0;
		}
		if (s[r].c != s[l].c && s[l].a > s[r].a) {
			S += s[r].a;
			s[l].a -= s[r].a;
			r = r - 1;
		}
		if (s[r].c != s[l].c && s[l].a < s[r].a) {
			S += s[l].a;
			s[r].a -= s[l].a;
			l = l + 1;
		}
		//if (s[r].c != s[l].c && s[l].a == s[r].a) {
		//		S += s[l].a;
		//		s[l].a = 0;
		//		r--;
		//	}
		if (s[r].c == s[l].c && s[l].a > s[r].a) {
			s[l].a -= s[r].a;
			r = r - 1;
		}
		if (s[r].c == s[l].c && s[l].a < s[r].a) {
			s[r].a -= s[l].a;
			l = l + 1;
		}
		//	if (s[r].c == s[l].c && s[l].a == s[r].a) {
		//		s[l].a = 0;
		//		r = r - 1;
		//	}
	}
	cout << S ;
	return 0;
}