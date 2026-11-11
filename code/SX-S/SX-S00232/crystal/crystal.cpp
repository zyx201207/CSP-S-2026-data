#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int maxn = 1e5 + 1;
const lint inf = 1e18;
template <typename T>
inline void fastread(T& x){
	x = 0; char ch = getchar(), f = 1;
	while(!isdigit(ch)){
		if(ch == '-') f = -f;
		ch = getchar();
	}
	while(isdigit(ch)){
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	x *= f;
}
template <typename T>
inline void fastprint(T x){
	if(x > 9) fastprint(x / 10);
	putchar(x % 10 + 48);
}
bool samediff = true;
lint n = 0, m = 0, a[maxn], diff0 = inf;

inline int spcheck(){
	if(!diff0) return n;
	lint cnt = 1, cost = 1, maxt = m / diff0;
	while(maxt >= cost){
		++cnt;
		maxt -= cost;
		++cost;
	}
	return min(cnt, n);
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	fastread(n);
	fastread(m);
	for(int i = 1; i <= n; ++i)
		fastread(a[i]);
	sort(a + 1, a + n + 1);
	if(n <= 2){fastprint((n == 2 && m >= diff0) ? 2 : 1); return 0;}
	diff0 = a[2] - a[1];
	for(int i = 3; i <= n; ++i)
		if(a[i] - a[i - 1] != diff0) samediff = false;
	if(samediff) fastprint(spcheck());
	else{
		lint ans = 0;
		for(int eg = n; eg >= 1; --eg){
			lint diff[maxn];
			for(int i = 1; i <= n; ++i)
				diff[i] = (a[eg] >= a[i]) ? a[eg] - a[i] : inf;
			sort(diff + 1, diff + n + 1);
			lint cnt = 1, m2 = m;
			for(int i = 2; i <= n; ++i){
				if(m2 >= diff[i]) ++cnt, m2 -= diff[i];
				else break;
			}
			ans = max(ans, min(cnt, n));
		}
		fastprint(ans);
	}
	return 0;
}
