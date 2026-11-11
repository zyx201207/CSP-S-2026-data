#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<vector>
#define mp make_pair
#define fo(i , x , y) for(int i = (x) ; i <= (y) ; i++)
#define go(i , x , y) for(int i = (x) ; i >= (y) ; i--)
#define chkmax(a , b) (a) = max((a) , (b))
#define chkmin(a , b) (a) = min((a) , (b))
#define local
#ifdef local
#define debug(x) cerr << #x" : " << x << ", "
#define debugn(x) cerr << #x" : " << x << "\n"
#define debugs(s) cerr << s
#define debugarr(a , n) cerr << #a" : " << "\n"; fo(i , 1 , n) cerr << a[i] << " "; cerr << "\n"
#elif
#define debug(x) "Chytholly is the happiest girl in the world!"
#define debugn(x) "Elaina"
#define debugs(s) "miku"
#define debugarr(a , n) "n-buna"
#endif
using namespace std;
const int maxn = 2e6;
int n;
long long d , a[maxn + 5];
long long dp[maxn + 5][3][4];
int f[maxn + 5];
void solve(){
	cin >> n >> d;
	fo(i , 1 , n) cin >> a[i];
	fo(i , 1 , n){
		f[i] = max(f[i - 1] , i);
		while(f[i] + 1 <= n and a[f[i] + 1] - a[i] <= d) f[i]++;
	}
//	debugarr(f , n);
	fo(i , 1 , n) fo(k , 0 , 2) fo(j , 1 , 3) dp[i][k][j] = 0;
	go(i , n - 1 , 1){
		if(f[i] == i){
			continue;
		}
		// dp[i][0]
		int l = i + 1 , r = f[i];
		dp[i][0][1] = dp[r][(r - l) > 2 ? 2 : (r - l)][1];
		dp[i][0][2] = dp[i][0][1];
		dp[i][0][3] = dp[r][(r - l) > 2 ? 2 : (r - l)][3] + (r - l + 1);
		fo(k , 1 , 2){
			fo(j , 1 , 3){
				int R1 = f[i] , R2 = f[i - 1] , R3 = (k == 2 ? f[i - 2] : i);
				long long add = (j == 3 ? R1 - R2 : 0) + (j == 1 ? R2 - R3 : 0);
				// find out next statue
				int nk = (R1 - i) - 1;
				if(nk > 2) nk = 2;
				//----------------
				int pre1 , pre2;
				if(j == 1) pre1 = pre2 = 1;
				else if(j == 2) pre1 = 1 , pre2 = 2;
				else pre1 = 2 , pre2 = 2;
				int nxt1 = 0 , nxt2 = 0;
				if(R3 == R1){
					nxt1 = 3;
				}
				else nxt1 = pre1 + (R2 == R1 ? pre2 : 0);
				if(R3 >= R1 - 1) nxt2 = 3;
				else nxt2 = pre1 + (R2 >= R1 - 1 ? pre2 : 0);
				if(nxt1 > 3) nxt1 = 3;
				if(nxt2 > 2) nxt2 = 2;
				if(nxt1 == 3)
					dp[i][k][j] = add;
				else if(nxt1 == 2)
					dp[i][k][j] = add + dp[f[i]][nk][3];
				else if(nxt2 == 2)
					dp[i][k][j] = add + dp[f[i]][nk][2];
				else dp[i][k][j] = add + dp[f[i]][nk][1];
			}
		}
	}
	long long ans = 0;
	fo(i , 1 , n) ans += dp[i][0][1];
	cout << ans << "\n";
}
int main(){
	ios :: sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	int c , T = 1;
	cin >> c >> T;
	while(T--) solve();
}