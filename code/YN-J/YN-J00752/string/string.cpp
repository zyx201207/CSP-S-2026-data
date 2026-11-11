#include <bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 2E5 + 5;
#define int long long

struct num {
	int num;
	char id;







} a[N] = {};
stack<num>q1;
stack<num>q2;
int ans = 1, n;

signed main() {
	IOS
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		char c;
		cin >> x >> c;
		a[i] = {x, c};
	}
	for (int i = 1; i <= n; i++) {
		q1.push(a[i]);
		q2.push(a[n - i + 1]);
	}
//	while (!q1.empty()) {
//		num t = q1.top();
//		cout << t.num << ' ' << t.id << '\n';
//		q1.pop();
//	}
//	while (!q2.empty()) {
//		num t = q2.top();
//		cout << t.num << ' ' << t.id << '\n';
//		q2.pop();
//	}
	while (!q1.empty()) {
		num t1 = q1.top(), t2 = q2.top();
		q1.pop(), q2.pop();
		int p = min(t2.num, t1.num);
		t2.num -= p;
		t1.num -= p;
		if (t1.num > 0)
			q1.push(t1);
		if (t2.num > 0)
			q2.push(t2);
//		cout << p << ':' << t1.id << ' ' << t1.num << ',' << t2.id << ' ' << t2.num << '\n';
		if (t1.id != t2.id) {
			ans += p;
		}
	}
	cout << ans / 2;
	return 0;
}
/*
2a2b1c
1c2b2a

2a3a
3a2a

3a1b7a9b
1a8b9a2b

a aa b aaaaa aa bbbbbbb bb
a bb b bbbbb aa aaaaaaa bb

1 2 1 5 2 7 2
*/