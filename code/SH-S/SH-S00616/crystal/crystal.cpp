#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;

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

ll n, m, a[N], s[N];
int ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read();
	m = read();
	for(int i = 1; i <= n; ++i) a[i] = read();
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
	for(int i = 1; i <= n; ++i) {
		int r = i, l = 1, mn = i;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(s[i] - s[mid - 1] >= (i - mid + 1)*a[i] - m) mn = mid, r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans, i - mn + 1);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
