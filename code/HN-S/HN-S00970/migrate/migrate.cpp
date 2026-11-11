#include<bits/stdc++.h>
#define def(i,a,b) for(i32 i = a;i <= b;i ++)
#define udef(i,a,b) for(i32 i = a;i >= b;i --)
#define Max(a,b) (a = max(a,b))
#define Min(a,b) (a = min(a,b))
#define fi first
#define se second
using namespace std;
using i32 = long long;
using i63 = long long;
const i63 N = 5e3 + 5,INF = 2e18,mod = 998244353;
i32 n;
i63 a[N],d;
i63 dp[N][N],f[N][N];
void solve(){
	cin >> n >> d;
	i32 ans = 0;
	def(i,1,n) cin >> a[i];
	def(len,1,n){
		for(i32 i = 1;len + i - 1 <= n;i ++){
			i32 j = len + i - 1;
			f[i][j] = INF,dp[i][j] = 0;
			if(a[j] - a[i] <= d) f[i][j] = 1,dp[i][j] = 1;
			else {
				i32 res = 0;
				def(k,i + 1,j - 1){
					Min(f[i][j],f[i][k] + f[k][j]);
				}
				def(k,i + 1,j - 1){
					if(f[i][j] == f[i][k] + f[k][j] && f[i][j] != INF) res += dp[i][k] * dp[k][j];
					if(res > 2) res = 3;
				}
				dp[i][j] = (f[i][j] != INF ? res : 0);
				ans += (res == 2);
			}			
		}
	}
	cout << ans << '\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	i32 c,_;
	cin >> c >> _;
	while(_--){
		solve();
	}
	return 0;
}

/*
看一下 代码与实际用途是否一致 如缩点后应使用缩点后的图b[i]
注意手打hack对拍 然后对症下要特判
谨防RE 队列一定要判非空 一定要判边界
没事别全开 long long
该break时别continue
备份备份 别一顿乱搞后该不如之前的
部分分 部分分
算一下会不会MLE
*/

