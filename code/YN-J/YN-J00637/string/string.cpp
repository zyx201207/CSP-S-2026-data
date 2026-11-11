#include <iostream>
#define LL long long
using namespace std;
const int N = 2e5 + 5;
LL int sum[N];

struct Node {
	LL int a;
	char c;
} node[N];
LL int cnt = 0;
LL int s[N];

int main(void) {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> node[i].a >> node[i].c;
		sum[i] = sum[i - 1] += node[i].a;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= node[i].a; j++) {
			s[sum[i - 1] + j] = node[i].c;
		}
	}
	LL int h = (n + 1) / 2;
	LL int l = sizeof(s);
	if (n % 2 == 1) {
		for (int i = 1; i < h; i++) {
			if (s[i] != s[l + 1 - i]) {
				s[l + 1 - i] = s[i];
				cnt++;
			}
		}
	} else {
		for (int i = 1; i <= h; i++) {
			if (s[i] != s[l + 1 - i]) {
				s[l + 1 - i] = s[i];
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}