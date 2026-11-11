#include <bits/stdc++.h>
using namespace std;
struct String{
	long long cnt;
	char word;
}s[200050];
int n, half, q[200050], ans;
int F(int y) {
	for (int i = 1; i <= n; i++) {
		if (y <= q[i]) return i;
	}
}
void A(int x) {
	int time = 1;
	for (int i = x; i >= 1; i--) {
		if (!(s[F(i)].word == s[F(i + 2 * time - 1)].word)) {
			ans++;	
		}
		time++;
	}
	return;
}
void B(int x) {
	int time = 1;
	for (int i = x; i >= 1; i--) {
		if (!(s[F(i)].word == s[F(i + 2 * time)].word)) {
			ans++;
		}
		time++;
	}
	return;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].cnt >> s[i].word;
		q[i] = q[i - 1] + s[i].cnt;
	}
	half = q[n] / 2;
	for (int i = 1; i <= n; i++) {
		if (half <= q[i]) {
			if (q[n] % 2 == 0) {
				A(half);
				break;
			}else {
				B(half);
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
