#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5000 + 10;
const int INF = 0x3f3f3f3f3f3f3f3f;

int c;
int T;
int n, d;
int a[N];
int nxt[N];
int cnt;
int ans;

int getstep(int l, int r){
	int mn = 1;
	int pos = l;
	while(nxt[pos] < r){
		if(nxt[pos] == pos) return -1;
		mn++;
		pos = nxt[pos];
	}
	return mn;
}

void dfs(int pos, int step, int r, int mn){
	if(cnt > 2) return;
	if(step != 0 && step + getstep(pos, r) == mn) cnt++;
	// cout << pos << " " << step << " " << r << " " << mn << " " << cnt << "\n";
	for(int i = pos + 1; i <= r; i++){
		if(abs(a[i] - a[pos]) <= d){
			dfs(i, step + 1, r, mn);
		}
	}
}

void check(int l, int r){
	int mn = getstep(l, r);
	// cout << l << " " << r << "\n";
	// cout << mn << "\n";
	// cout << "\n";
	if(mn == -1) return; 
	dfs(l, 0, r, mn);
	if(cnt == 2) ans++;
}

void solve(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		nxt[i] = i;
		for(int j = i + 1; j <= n; j++){
			if(abs(a[j] - a[i]) <= d){
				nxt[i] = j;
			} else {
				break;
			}
		}
	}
	// for(int i = 1; i <= n; i++){
	// 	cout << nxt[i] << " ";
	// }
	// cout << "\n";
	for(int i = 1; i <= n; i++){
		for(int j = i + 3; j <= n; j++){
			cnt = 0;
			check(i, j);
		}
	}
	cout << ans << "\n";
	ans = 0;
	return ;
}

signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> c >> T;
	while(T--){
		solve();
	}
	return 0;
}	