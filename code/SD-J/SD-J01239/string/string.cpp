#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
struct node {
	long long a;
	char c;
} mp[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> mp[i].a >> mp[i].c;
	}
	long long cnt = 0;
	int m = n;
	int l = 1, r = n;
	while (l <= r) {
		if (mp[l].c != mp[r].c) {
			cnt += min(mp[l].a, mp[r].a);
			if (mp[l].a < mp[r].a) {
				mp[r].a -= mp[l].a;
				l++;
			} else if (mp[l].a > mp[r].a) {
				mp[l].a -= mp[r].a;
				r--;
			} else {
				l++;
				r--;
			}
		} else {
			if (mp[l].a < mp[r].a) {
				mp[r].a -= mp[l].a;
				l++;
			} else if (mp[l].a > mp[r].a) {
				mp[l].a -= mp[r].a;
				r--;
			} else {
				l++;
				r--;
			}
		}
	}
	printf("%lld\n", cnt);
	
	return 0;
}
