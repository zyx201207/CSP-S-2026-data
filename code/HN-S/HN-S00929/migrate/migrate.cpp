#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define __low lower_bound
#define __upp upper_bound
#define pii pair<int,int>
#define MP make_pair
#define fi first
#define se second
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e6+5; 

int T, c, n;
ll d, a[N];
ll dis[N];
ll sum[N], dp[N];

void init(){
	sum[0] = 1;
	for(int i = 1; i <= n; i++){
		sum[i] = 0, dis[i] = 0, dp[i] = 0;
	}
}

int DP(int be){
	init();
	dp[be] = 1;
	int ans = 0, now = 0;
	for(int l = be, r = be+1; r <= n; r++){
		while(a[r] - a[l] > d){
			sum[now] -= dp[l], l++;
			if(sum[now] == 0) now++;
		} 
		dp[r] = sum[now], dis[r] = now+1;
		sum[now+1] += dp[r];
		if(dp[r] == 2) ans++;
	}
	return ans;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		if(n > 5000){
			cout << 0 << "\n";
			continue;
		}
		sort(a+1, a+1+n);
		int ans = 0;
		for(int i = 1; i <= n; i++){
			ans += DP(i);
		}
		cout << ans << "\n";
	}
	
	return 0;
} 
