#include <bits/stdc++.h>
#define int long long
#define P pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 5;
const int M = 3e5 + 5;
int n, m;
int a[N];
int vis[M], ans[M];
P b[N];
void solve1() {
	stack<int> st;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (vis[a[j]]) {
				while (!st.empty() && st.top() != a[j]) {
					vis[st.top()] = 0;
					st.pop();
				}
			} else {
				vis[a[j]] = 1;
				st.push(a[j]);
			}
		}
		for (int j = i; j <= n; j++) {
			ans[a[j]] += vis[a[j]];
			vis[a[j]] = 0;
		}
		while (!st.empty()) {
			st.pop();
		}
	}
	for (int i = 1; i <= m; i++) {
		printf("%lld", ans[i]);
		if (i != m) {
			printf(" ");
		}
	}
}
void solve2() {
	int sum = 1;
	int p = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i] != a[i - 1]) {
			b[++p] = {a[i - 1], sum};
			sum = 1;
		} else {
			sum++;
		}
	}
	b[++p] = {a[n], sum};
	stack<int> st;
	for (int i = 1; i <= p; i++) {
		for (int j = i; j <= p; j++) {
			if (vis[b[j].fi]) {
				while (!st.empty() && st.top() != b[j].fi) {
					vis[st.top()] = 0;
					st.pop();
				}
			} else {
				vis[b[j].fi] = 1;
				st.push(b[j].fi);
			}
		}
		for (int j = i; j <= p; j++) {
			ans[b[j].fi] += vis[b[j].fi] * b[i].se;
			vis[b[j].fi] = 0;
		}
		while (!st.empty()) {
			st.pop();
		}
	}
	for (int i = 1; i <= m; i++) {
		printf("%lld", ans[i]);
		if (i != m) {
			printf(" ");
		}
	}
}
void solve3() {
	ans[a[n]] = n;
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[n]) {
			ans[a[i]]++;
		}
	}
	printf("%lld %lld", ans[1], ans[2]);
}
void solve4() {
	for (int i = 1; i <= n; i++) {
		ans[a[i]]++;
	}
	for (int i = 1; i <= m; i++) {
		printf("%lld ", ans[i]);
		if (i != m) {
			printf(" ");
		}
	}
}
void solve() {
	scanf("%lld%lld", &n, &m);
	int sum = 0;
	bool A = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		if (i != 1) {
			sum += (a[i] != a[i - 1]);
			if (a[i] < a[i - 1]) {
				A = 0;
			}
		}
	}
	if (n <= 5000) {
		solve1();
		return ;
	} else if (sum <= 4999) {
		solve2();
		return ;
	} else if (m == 2) {
		solve3();
		return ;
	} else if (A) {
		solve4();
		return ;
	}
	solve2(); 
}
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	solve();
	return 0;
}

/*
无聊……
考场睡了 1h
我要让这个文件的大小达到2601字节
这道题咋写？？？
只能骗72pts qwq
不过这样应该能 J1=
我可以在这里写邮寄？
似乎不想写
还差一点点
shy的考试年排是1442
刚刚有2515字节
到了！！ 
*/ 
