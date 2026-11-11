#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, t;
int n;
ll d;
ll a[2000005];
int ma[2000005], as1[2000005];

inline void solve1(){ // 暴力 
	ll ans = 0;
	for(int i = 1;i <= n;i++){ // 从i出发 
		for(int j = 1;j <= n;j++){
			ma[j] = 1e9, as1[j] = 0;
		} 
		ma[i] = 0;
		as1[i] = 1;
		for(int j = i;j <= n;j++){ // 已到达位置 
			if(as1[j] == 2){
				ans ++;
			}
			for(int k = j + 1;k <= n;k++){
				if(a[k] - a[j] > d) break;
				if(ma[j] + 1 < ma[k]){
					ma[k] = ma[j] + 1;
					as1[k] = as1[j];
				}else if(ma[j] + 1 == ma[k]){
					as1[k] += as1[j];
				}
			}
		}
	} 
	cout << ans << "\n";
}

inline void solve2(){
	if(n == 1){
		cout << "0\n";
		return;
	}
	ll ct = a[2] - a[1];
	int kua = d / ct;
	if(kua > 1 && n >= kua + 1) cout << n - kua - 1<< "\n"; 
	else cout << "0\n"; 
}

inline void solve3(){
	int mid = 0;
	for(int i = 1;i <= n;i++){
		if(a[i] - a[1] <= d && a[n] - a[i] <= d){
			mid = i;
			break;	
		}
	}
	int l = mid - 1, r = mid + 1;
	int ans = 0;
	while(l > 0 && r <= n){
		if(a[r] - a[l] <= d && a[r] - a[l + 1] <= d && (l - 1 > 0 || a[r] - a[l - 1] > d)){
			ans ++;
			r ++;
		}else if(l - 1 > 0 || a[r] - a[l - 1] > d){
			l --;
		}
	}
	cout << ans << "\n";
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t --){
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		if(c == 11 || c == 12) solve2();
		else if(c == 13 || c == 14) solve3();
		else solve1();
	}
	return 0;
}

