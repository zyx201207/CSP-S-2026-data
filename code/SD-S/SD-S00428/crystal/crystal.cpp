#include <bits/stdc++.h>
using namespace std;
#define int long long

//#define LOCAL
#define SIZE (1 << 20)

#ifndef LOCAL
	char in[SIZE], *p1, *p2;
	#define getchar() (p1 == p2 && (p2 = (p1 = in) + fread(in, 1, SIZE, stdin)), p1 == p2 ? EOF : *p1 ++)
#endif

int read(){
	int x = 0, f = 1, ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	} while(ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	} return x * f;
}

const int N = 1e6 + 10;
int n, m, a[N], sum[N], ans;
map<int, int> mp;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i)
		a[i] = read();
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; ++ i){
//		cout << a[i] << " \n"[i == n];
		++ mp[a[i]];
		sum[i] = sum[i - 1] + a[i];
		int l = 1, r = i, res = i;
		while(l <= r){
			int mid = (l + r) >> 1ll;
			if((i - mid) * a[i] - (sum[i - 1] - sum[mid - 1]) <= m)
				r = mid - 1, res = mid;
			else l = mid + 1;
		} 
		ans = max(ans, i - res + 1);
	} cout << ans << "\n";
	
	return 0;
}

