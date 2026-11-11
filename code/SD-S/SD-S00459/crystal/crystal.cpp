#include <bits/stdc++.h>
#define pb emplace_back
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
//using i128 = __int128;
//using u128 = unsigned __int128;
using namespace std;
bool ST;

const int N = 5e5 + 5;

int n,ans;
i64 m,t,a[N],tak[N];

bool ED;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	mt19937 rnd(time(0));
	
	cin >> n >> m;
	for (int i = 1;i <= n;++i){
		cin >> a[i],tak[i] = a[i];
	}sort(a + 1,a + n + 1,[&](i64 x,i64 y){return x > y;});
	sort(tak + 1,tak + n + 1,[&](i64 x,i64 y){return x > y;});
	t = unique(tak + 1,tak + n + 1) - tak - 1;
	int l = 1,r = 0;
	i64 sum = 0;
	for (int i = 1;i <= t;++i){
		i64 v = tak[i];
		sum += 1ll * max(0,r - l + 1) * (v - tak[i - 1]);
		while (l <= n && a[l] > v) sum -= v - a[l],++l;
		if (l > n) break;
		r = max(r,l);
		while (r < n && sum + v - a[r + 1] <= m) ++r,sum += v - a[r];
		ans = max(ans,r - l + 1);
//		cout << v << ' ' << l << ' ' << r << ' ' << sum << '\n';
	}cout << ans;
	
//	cerr << "\ntime used: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000.0 << " ms";
//	cerr << "\nmemory used: " << abs(&ST - &ED) / 1024.0 / 1024.0 << " MB";
	return 0; 
}/*
5 5
1 2 4 8 9
*/
