#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int,int>;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c , t;
	cin >> c >> t;
	while(t--){
		int n , d;
		cin >> n >> d;
		vector<i64> a(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		if(a[n] - a[1] <= d){
			cout << 0 << '\n';
			continue ;
		}
		if(n <= 3){
			cout << 0 << '\n';
			continue ;
		}
		a[0] = -1e18;
		vector<int> ldp , lsdp , rdp , rsdp;
		{
			vector<int> dp(n + 1) , sdp(n + 1);
			int nw = 1 , llnw = 0 , lrnw = 0;
			for(int i = 1; i <= n; i++){
				while(a[i] - a[nw] > d) nw++;
				dp[i] = i - nw + 1;
				if(nw == i){
					continue ;
				}
				while(a[nw] - a[llnw] > d) llnw++;
				while(a[nw + 1] - a[lrnw] > d) lrnw++;
				dp[i] += sdp[lrnw-1] - sdp[llnw-1];
				sdp[i] = sdp[i-1] + sdp[i];
			}
			swap(dp,ldp);
			swap(sdp,lsdp);
		}
		auto b = a;
		{
			vector<int> dp(n + 1) , sdp(n + 1);
			int nw = 1 , llnw = 0 , lrnw = 0;
			reverse(a.begin()+1,a.end());
			for(int i = 1; i <= n; i++) a[i] = -a[i];
			for(int i = 1; i <= n; i++){
				while(a[i] - a[nw] > d) nw++;
				dp[i] = i - nw + 1;
				if(nw == i){
					continue ;
				}
				while(a[nw] - a[llnw] > d) llnw++;
				while(a[nw + 1] - a[lrnw] > d) lrnw++;
				dp[i] += sdp[lrnw-1] - sdp[llnw-1];
				sdp[i] = sdp[i-1] + sdp[i];
			}
			swap(dp,rdp);
			swap(sdp,rsdp);
			swap(a,b);
		}
		long long ans = 0;
		{
			int r1 = upper_bound(a.begin()+1,a.end(),a[1] + d) - a.begin() - 1;
			int l1 = upper_bound(a.begin()+1,a.end(),a[2] + d) - a.begin() - 1;
			ans += lsdp[l1] - lsdp[r1];
		}
		{
			int r1 = upper_bound(b.begin()+1,b.end(),b[1] + d) - b.begin() - 1;
			int l1 = upper_bound(b.begin()+1,b.end(),b[2] + d) - b.begin() - 1;
			ans += rsdp[l1] - rsdp[r1];
		}
//		for(int i = 1; i <= n; i++){
//			cout << rdp[i] << " \n"[i==n];
//		}
		for(int i = 2; i < n - 1; i++){
			int r = n - i , l = i;
			i64 L , R;
			int ll = lower_bound(a.begin()+1,a.end(),a[l+1]-d) - a.begin();
			if(ll != 0) ll--;
			int lr = lower_bound(a.begin()+1,a.end(),a[l+2]-d) - a.begin();
			if(lr != 0) lr--;
			L = lsdp[lr] - lsdp[ll];
			int rl = lower_bound(a.begin()+1,a.end(),a[l+1]-d) - a.begin();
			if(rl != 0) rl--;
			int rr = lower_bound(a.begin()+1,a.end(),a[l+2]-d) - a.begin();
			if(rr != 0) rr--;
			R = rsdp[rr] - rsdp[rl];
			ans += L * R;
		}
		cout << ans << '\n';
	}
}
/*
定义dp[i][j]表示第i个岛屿为终点，有j个最短路径的最靠前的岛屿，以及路径长度 
也就是说,
在dp[i][2]以前的岛屿到达i有超过2条路径
在[dp[i][2],dp[i][1])内的岛屿到达i恰有2条路径
find the dp val
for j = 1:
get the islands distance within d and with same length
if cnt of find >= 2 -> only

let's brute first

identify dp[i][j][k] = length(default = inf)
i:from i
j:to j
k:have k min routes
length: min routes' length
identify min[i][j] as the min length between i and j
dp[i][j][1] = [have only 1 md in (i,j) that dp[i][md][1] + dp[md][j][1] = min[i][j]]
dp[i][j][2] = [have only 2 md in (i,j) that dp[i][md][1] + dp[md][j][1] = min[i][j]
			or have only 1 md in (i,j) that dp[i][md][1] + dp[md][j][2] = min[i][j]
			or have only 1 md in (i,j) that dp[i][md][2] + dp[md][j][1] = min[i][j]] * min[i][j]
*/
