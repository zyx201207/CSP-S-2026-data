#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2500005;
const int M = 1505;
const int INF = 1e9;
const int mod = 998244353;
int a[N], maxidx[N], minidx[N], sum = 0, minn = INF;
int n, d;
void dfs(int st, int s, int t, int now){
	if(st >= t){
		minn = min(minn, now);
		return ;
	}
	for(int i = st + 1; i <= n; i++){
		if(a[i] - a[st] <= d){
			dfs(i, s, t, now + 1);
		}
	}
}
void dfs2(int st, int s, int t, int now){
	if(st >= t){
		if(now == minn) sum ++; 
		return ;
	}
	for(int i = st + 1; i <= n; i++){
		if(a[i] - a[st] <= d){
			dfs(i, s, t, now + 1);
		}
	}
}
void work(){
	cin >> n >> d;
	int fA = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i != 1 && a[i] - a[i - 1] != a[2] - a[1]){
			fA = 0;
		}
	}
	int fC = (a[n] - a[1] <= 10 * d);
	int idx = upper_bound(a + 1, a + 1 + n, a[1] + d) - a - 1;
	int fB = (a[n] - a[idx] <= d);
//	cout << fA << "\n";
	if(fA){
		int k = a[2] - a[1];
		int opt = d / k, ans = 0;
		if(opt < 2){
			cout << "0\n";
			return ;
		}
		cout << max(0ll, n - 2 * opt + 1) << "\n";
	}/*else if(fB){
		for(int i = 1; i <= n; i++){
			if(a[1] + d >= a[i] && a[i] + d >= a[n]){
				
			}
		}
	}else if(fC){
		
	}*/else{
		int ans = 0, lst = 1;
		for(int i = 1; i <= n; i++){
			maxidx[i] = upper_bound(a + 1, a + 1 + n, a[i] + d) - a - 1;
		}
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				sum = 0;
				minn = INF;
				dfs(i, i, j, 0);
//				cout << i << " " << j << " " << minn << "\n"; 
				dfs2(i, i, j, 0);
				if(sum == 2){
					ans ++;
				}
			} 
		}
		cout << ans << "\n";
	}
	return ;
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1, c;
	cin >> c >> t;
	while(t--){
		work();
	} 
	return 0;
} 
//luogu uid 910628 Luna_From_Starry 球上神人共赏 
