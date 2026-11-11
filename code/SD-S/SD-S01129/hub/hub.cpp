#include<bits/stdc++.h>
#define int long long
#define PII pair< int, int >

using namespace std;

const int N = 1e5 + 5, mod = 998244353;
int c, T, n, k, a;

template< typename T > void read(T &x){x = 0;char ch = getchar();bool f = true;while (ch < '0' || ch > '9'){if (ch == '-') f = !f;ch = getchar();}while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();}x = (f ? x : -x);}
template< typename T, typename ... L > void read(T &a, L && ... b){read(a);read(b ...);}
int ksm(int a, int b, int p){int ans = 1;while (b){if (b & 1) ans = ans * a % p;b >>= 1;a = a * a % p;}return ans;}
void solve(){
	read(n, k);
	for (int i = 1; i < n; i++) read(a, a);
	if (n == k) puts("0");
	else puts("1");
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out","w",stdout);
	read(c, T);
	while (T--) solve();
	return 0;
}
/*
luogu uid:1070982
Çë¹Ø×¢Ð»Ð» 
*/
