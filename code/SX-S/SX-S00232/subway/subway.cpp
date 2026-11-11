#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int maxn = 501, maxm = 5e5 + 1;
const lint inf = 1e18;
template <typename T>
inline void fastread(T& x){
	x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
}
template <typename T>
inline void fastprint(T x){
	if(x > 9) fastprint(x / 10);
	putchar(x % 10 + 48);
}
int c = 0, n = 0, m = 0, d = 0, q = 0;
lint w[maxm], a[maxn][maxn];
vector<int> blng[maxm];
vector<lint> leng[maxm];

inline void init(){
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			a[i][j] = inf;
	for(int i = 1; i <= n; ++i)
		a[i][i] = 0;
	for(int i = 1; i <= m; ++i){
		if(blng[i].size() <= 1) continue;
		for(int li1 = 0; li1 < blng[i].size() - 1; ++li1)
			for(int li2 = li1 + 1; li2 < blng[i].size(); ++li2){
				int s1 = blng[i][li1], s2 = blng[i][li2];
				lint d1 = leng[i][li1], d2 = leng[i][li2];
				a[s1][s2] = a[s2][s1] = min(a[s1][s2], d1 + d2);
			}
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			for(int k = 1; k <= n; ++k)
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	fastread(c); fastread(n); fastread(m); fastread(d); fastread(q);
	for(int i = 1; i <= m; ++i) fastread(w[i]);
	for(int i = 1, ki = 0; i <= n; ++i){
		fastread(ki);
		for(int j = 1, v = 0, l = 0; j <= ki; ++j){
			fastread(v); fastread(l);
			blng[v].push_back(i);
			leng[v].push_back(l);
		}
	}
	init();
	for(int i = 1, st = 0, ed = 0; i <= q; ++i){
		fastread(st); fastread(ed);
		lint ans = inf;
		for(int li1 = 0; li1 < blng[st].size(); ++li1)
			for(int li2 = 0; li2 < blng[ed].size(); ++li2){
				int sst = blng[st][li1], sed = blng[ed][li2];
				lint dst = leng[st][li1], ded = leng[ed][li2];
				ans = min(ans, dst + ded + a[sst][sed]);
			}
		fastprint(ans + w[st] + w[ed]);
		putchar('\n');
	}
	return 0;
}
