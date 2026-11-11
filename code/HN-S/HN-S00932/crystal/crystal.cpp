#include<bits/stdc++.h>
#define int long long

#define rep(K,F,T) for(int K=F;K<=T;K++)
#define rip(K,F,T) for(int K=F;K>=T;K--)

//#define lson (x<<1)
//#define rson ((x << 1) | 1)
//#define mid ((l + r) >> 1)

using namespace std;

namespace florr{
	int read() {
		int x = 0, f = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9') {
			if(ch == '-') f = -1;
			ch = getchar();
		}
		while(ch >= '0' && ch <= '9') {
			x = x * 10 + (ch - '0');
			ch = getchar();
		}
		return x * f;
	}
	void write(int x) {
		if(x < 0) {
			putchar('-');
			x = -x;
		}
		if(x > 9) write(x / 10);
		putchar(x % 10 + '0');
		return;
	}
}
using namespace florr;
const int MAXN = 5e5 + 10;
int n, m, a[MAXN];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out", "w",stdout);
	n = read();
	m = read();
	rep(i,1,n) a[i] = read();
	sort(a +1, a+1+n);
	int sum = 0, ans = 0;
	int pos = 1;
	rep(i,1,n) 
	{
		sum += a[i];
		while((i - pos + 1) * a[i] - sum > m ) {
			sum -= a[pos ++];
		}
		ans = max(ans, i - pos + 1);
	}
	write(ans);
	return 0;
}
/*
*/

