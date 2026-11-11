#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2000005;

namespace IO {

ll read() {
	ll ret = 0;
	int tag = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') tag = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		ret = ret*10 + ch - 48;
		ch = getchar();
	}
	ret *= tag;
	return ret;
}

void print(ll x) {
	if(!x) {
		putchar(48);
		return;
	}
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	int stk[25], top = 0;
	for(; x; x /= 10) stk[++top] = x % 10;
	for(; top; --top) putchar(stk[top] + 48);
}

}

using IO::read;
using IO::print;

int c, T, n;
ll d, a[N], ans;
int pre[N], nxt[N], cntp[N], cntn[N];
bool vis[N];

void sol() {
	ans = 0;
	for(int i = 1; i <= n; ++i) {
		pre[i] = nxt[i] = cntp[i] = cntn[i] = vis[i] = 0;
	}
	for(int i = 1, j = 1; i <= n; ++i) {
		while(j < n && a[j + 1] - a[i] <= d) ++j;
		nxt[i] = j;
		++cntn[j];
	}
	for(int i = n, j = n; i >= 1; --i) {
		while(j > 1 && a[i] - a[j - 1] <= d) --j;
		pre[i] = j;
		++cntp[j];
	}
	for(int i = 1; i <= n; ++i) {
		if(vis[i]) continue;
		for(int j = i, tot = 0; j <= n; j = nxt[j], ++tot) {
			vis[j] = 1;
			if(i != j) {
				if(pre[j] != j - 1) ans += 1LL*tot*cntp[j - 1];
			}
			if(nxt[j] == j || pre[nxt[j]] != j) break;
		}
	}
	for(int i = 1; i <= n; ++i) vis[i] = 0;
	for(int i = n; i >= 1; --i) {
		if(vis[i]) continue;
		for(int j = i, tot = 0; j >= 1; j = pre[j], ++tot) {
			vis[j] = 1;
			if(i != j) {
				if(nxt[j] != j + 1) ans += 1LL*tot*cntn[j + 1] - (nxt[pre[j + 1]] == j + 1);
			}
			if(pre[j] == j || nxt[pre[j]] != j) break;
		}
	}
	for(int i = 1; i <= n; ++i) cout << pre[i] << ' ';
	cout << '\n';
	for(int i = 1; i <= n; ++i) cout << nxt[i] << ' ';
	cout << '\n';
	print(ans);
	putchar(10);
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read();
	T = read();
	while(T--) {
		n = read();
		d = read();
		for(int i = 1; i <= n; ++i) a[i] = read();
		sol();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
