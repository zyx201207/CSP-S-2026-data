#include<bits/stdc++.h>
#define LoveCyrene ios :: sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define LoveAnastasya freopen("crystal.in", "r", stdin)
#define LoveOdette freopen("crystal.out", "w", stdout)
#define int long long int
using namespace std;;
constexpr int N = 5e5 + 9178;
constexpr int INF = 1e18;
int a[N];

struct SEG{
	int sum[N << 2], len[N << 2], tag[N << 2];
	
	void pushup(int x){
		sum[x] = sum[x << 1] + sum[x << 1 | 1]; 
	}
	
	void apply(int x, int v){
		sum[x] += len[x] * v;
		tag[x] += v;
	}
	
	void pushdown(int x){
		apply(x << 1, tag[x]);
		apply(x << 1 | 1, tag[x]); 
		tag[x] = 0;
	}
	
	void build(int x, int l, int r){
		len[x] = r - l + 1;
		if(l == r){
			
			return;
		}
		int mid = (l + r) >> 1;
		build(x << 1, l, mid);
		build(x << 1 | 1, mid + 1, r);
		pushup(x);
	}
	
	void modify(int x, int l, int r, int ql, int qr, int v){
		if(l > r || ql > r || qr < l) return;
		if(ql <= l && r <= qr){
			apply(x, v);
			return;
		}
		pushdown(x);
		int mid = (l + r) >> 1;
		modify(x << 1, l, mid, ql, qr, v);
		modify(x << 1 | 1, mid + 1, r, ql, qr, v);
		pushup(x);
	}
	
	int qsum(int x, int l, int r, int ql, int qr){
		if(l > r || ql > r || qr < l) return 0;
		if(ql <= l && r <= qr){
			return sum[x];
		}
		pushdown(x);
		int mid = (l + r) >> 1, ans = 0;
		ans += qsum(x << 1, l, mid, ql, qr);
		ans += qsum(x << 1 | 1, mid + 1, r, ql, qr);
		return ans;
	}
} seg; 

int Anastasya(int n, int m){
	sort(a + 1, a + n + 1);
	seg.build(1, 1, n);
	int ans = 0;
	for (int i = 1, l = 1; i <= n; ++i){
		seg.modify(1, 1, n, 1, i - 1, a[i] - a[i - 1]);
		while(seg.qsum(1, 1, n, l, i) > m && l <= i){
			l++;
		}
		ans = max(ans, i - l + 1);
	}
	return ans;
} 

signed main(){
	LoveAnastasya;
	LoveOdette;
	LoveCyrene;
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	cout << Anastasya(n, m);
	return 0;
}
/*
5 5
1 2 4 8 9

3

5 8
-3 -1 2 2 7

4
*/