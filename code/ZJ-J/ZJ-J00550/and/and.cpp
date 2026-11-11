#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10; 
int a[N], ejz[N][45], cnt[N], b[N], c[N], mp[45], an[45];
int n, m, st, ans, q = 1;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	/*
	3 2
	4 3 3
	*/
	for(int i = 1; i <= n; i++){//2e5 * 30 = 6e6
		cin >> a[i];
		int ai = a[i];
		c[i] = i;
		while(ai > 0){
			ejz[i][++cnt[i]] = ai % 2;
			ai /= 2;
		}
		st = max(st, cnt[i]);
	}
	/*
	b数组筛选，复制给 c数组
	提供下一轮筛选 
	*/
	for(int i = st; i > 0; i--){
		int cn = 0, cc = 0;
		for(int j = 1; j <= n; j++){
			if(ejz[c[j]][i] == 1) cc++;
		}
		if(cc >= m){
			for(int j = 1; j <= n; j++){
				if(ejz[c[j]][i] == 1){
					b[++cn] = c[j];
				}
			}
			memcpy(c, b, sizeof b);
			n = cn;
			an[i] = 1;
		}
	}
	for(int i = 1; i <= st; i++){
		ans += (q * an[i]);
		q *= 2;
	}
	cout << ans;
	return 0;
}
