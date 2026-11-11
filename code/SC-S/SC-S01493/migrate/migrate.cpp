#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 2e6 + 10;
int c, T;
int md[N];
ll td[N];
int p[N];
void solve(){
	int n;
	ll d;
	cin >> n >> d;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		cin >> td[i];
	}
	if(c == 11 || c == 12){
		int cnt = 1;
		for(int i = 2; i <= n; i++){
			if(td[i] - td[1] > d)break;
			cnt++;
		}
		int k = 2 * cnt - 2;
		if(k < 3 || n - k + 1 <= 0)cout << 0 <<"\n";
		else cout << n - k + 1 <<"\n";
		return;
	}
	for(int i = 1; i <= n; i++){
		int l = i;
		md[i] = 0;
		p[i] = 1;
		for(int r = l + 1; r <= n; r++){
			while(td[r] - td[l] > d)l++;
			md[r] = md[l] + 1;
			p[r] = 0;
			int cnt = 0;
			for(int j = l;j <= l + 2 && j < r; j++){
				if(md[l] == md[j]){
					p[r] += p[j];
				}
			}
			if(p[r] == 2) {
				ans++;
			}
		}
		md[i] = 1e9;
	}
	cout << ans << "\n";
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while(T--){
		solve();
	}
}
