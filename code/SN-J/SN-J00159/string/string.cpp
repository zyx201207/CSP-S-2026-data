#include <bits/stdc++.h>
using namespace std;
struct node {
	long long a;
	long long id = 0;
	char c;
}str[200003];
int n;
long long ans;
long long s_length;
int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> str[i].a >> str[i].c;
		str[i].id = str[i].a + str[i - 1].id;
		s_length += str[i].a;
	}
	long long l = 1, r = s_length;
	int idx_pre = 1, idx_last = n;
	while (l <= r) {
		char cur_l, cur_r;
		r = s_length + 1 - l;
		if (l > str[idx_pre].id) {
			idx_pre++;
		}
		if (r <= str[idx_last - 1].id) {
			idx_last--;
		}
		cur_l = str[idx_pre].c;
		cur_r = str[idx_last].c;
		if (cur_l == cur_r) {
			++l;
			--r;
			continue;
		}
		ans++;
		++l;
		--r;
	}
	cout << ans << '\n';
	return 0;
}
