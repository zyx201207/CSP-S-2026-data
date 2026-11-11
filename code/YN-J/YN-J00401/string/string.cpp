#include <bits/stdc++.h>
using namespace std;
int zi[1000];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int a;
	char s;
	int y = 0, l, l1;
	queue<char>q;
	stack<char>zhan;
	for (int i = 0; i < n; i++) {
		cin >> a >> s;
		zi[int(s)] = zi[int(s)] + a;
		if (n < 500) {
			for (int j = 0; j < a; j++) {
				q.push(s);
				zhan.push(s);
			}
		} else {
			l = s;
			if (s != l) {
				y++;
			}
		}
	}
	for (int i = 0; i < q.size(); i++) {
		if (q.front() != zhan.top()) {
			y++;
		}
	}
	sort(zi, zi + 1000);
	if (y == 0) {
		cout << 0;
		return 0;
	} else {
		cout << zi[999];
	}
	return 0;
}