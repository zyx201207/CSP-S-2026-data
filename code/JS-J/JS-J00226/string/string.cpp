#include <bits/stdc++.h>
using namespace std;
int n;
long long ans, need;
pair<int, char> s[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %c", &s[i].first, &s[i].second);
	}
	for (int i = 1, j = n; i < j;) {
		if (s[i].first == s[j].first) {
			if (s[i].second != s[j].second) {
				ans += s[i].first;
			}
			++i;
			--j;
		}
		else if (s[i].first < s[j].first) {
			s[j].first -= s[i].first;
			if (s[i].second != s[j].second) {
				ans += s[i].first;
			}
			++i;
		}
		else if (s[i].first > s[j].first) {
			s[i].first -= s[j].first;
			if (s[i].second != s[j].second) {
				ans += s[j].first;
			}
			--j;
		}
	}
	printf("%lld", ans);
	return 0;
}
