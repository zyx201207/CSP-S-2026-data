#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
	T s = 0; int st = 1; char c = getchar();
	while(c < '0' || c > '9') (c == '-') && (st = -1), c = getchar();
	while(c >= '0' && c <= '9') s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
	x = s * st;
}
template<typename T, typename... Args> inline void read(T &x, Args &...args){
	read(x), read(args...);
}
template<typename T> inline void write(T x){
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
#define LL long long 
#define PII pair<int, int> 
#define ull unsigned long long 
const int N = 5e5 + 5;
LL a[N], sum[N << 2], tnc[N << 2];
void Add(int L, LL C, int rt, int l, int r){
	if(l == r){
		++tnc[rt];
		sum[rt] += C;
		return;
	}
	int mid = l + r >> 1;
	if(L <= mid) Add(L, C, rt << 1, l, mid);
	else Add(L, C, rt << 1 | 1, mid + 1, r);
	tnc[rt] = tnc[rt << 1] + tnc[rt << 1 | 1];
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
int Find(int R, LL k, LL m, int rt, int l, int r){
	if(l == r) return R - l + 1 - (sum[rt] + tnc[rt] * k > m);
	int mid = l + r >> 1;
	if(mid + 1 > R) return Find(R, k, m, rt << 1, l, mid);
	LL s = sum[rt << 1 | 1] + tnc[rt << 1 | 1] * k;
//	cerr << mid + 1 << ' ' << r << ' ' << sum[rt << 1 | 1] << ' ' << m << ' ' << s << '\n';
	if(s >= m) return Find(R, k, m, rt << 1 | 1, mid + 1, r);
	else return Find(R, k, m - s, rt << 1, l, mid);
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	freopen("crystal4.in", "r", stdin);
	int n; LL m;
	read(n, m);
	for(int i = 1; i <= n; ++i){
		read(a[i]);
	}
	sort(a + 1, a + 1 + n);
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		Add(i, -a[i], 1, 1, n);
		int cnt = Find(i, a[i], m, 1, 1, n);
//		for(int j = i; j >= 1; --j){
//			sum += a[i] - a[j];
//			if(sum > m) break;
//			++cnt;
//		}
//		cerr << i << ": " << cnt << '\n';
		ans = max(ans, cnt);
	}
	write(ans);
	return 0;
}