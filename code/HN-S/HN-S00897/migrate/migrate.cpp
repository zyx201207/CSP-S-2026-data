#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int c, T, n, d, a[N], f[N], dis[N], t[N];
void solve(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(c <= 10){
		int ans = 0;
		for(int i = 1, pos, sum; i <= n; i++){
			for(int j = 0; j <= n; j++) t[j] = 0;
			f[i] = 1, pos = i, sum = 1, dis[i] = 0, t[0] = 1;
			for(int j = i - 1, pos = i; j >= 1; j--){
				while(a[pos] - a[j] > d) t[dis[pos]] -= f[pos], pos--;
				f[j] = t[dis[pos]], dis[j] = dis[pos] + 1, t[dis[j]] += f[j];
				if(f[j] == 2) ans++;
			}
		}
		cout << ans << '\n';
	} 
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> T;
	while(T--) solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

这题可以拿40pts的暴力

不是啊，怎么感觉人均200+，1=线不会要起飞了吧 

怎么感觉都是可做的，woc不是大哥，我想打NOIP啊 

17：44 40pts 

不对，等差数列有分可以拿 
*/
