#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,t,n,d,a[2000010],f[2000010],c[2000010];
void solve(){
	cin >> n >> d;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(a[n] - a[1] <= d){
		cout << "0\n";
		return ;
	}
	int ans = 0;
	if(x > 10 && x < 13){
		a[n + 1] = a[n] + a[2] - a[1];
		bool ok = 0;
		for(int i = 4;i <= n;i++){
			if(i % 2 == 0 && a[i] - a[1] < 2 * d && a[i + 1] - a[1] >= 2 * d) ok = 1;
			if(ok) ans++;
		}
		cout << ans << '\n';
		return ;
	}
	if(x > 12 && x < 15){
		int l = 1,r = 0;
		for(int i = 1;i <= n;i++){
			while(a[i] - a[l] > d) l++;
			while(r < n && a[r + 1] - a[i] <= d) r++;
			f[i] = l,c[i] = r;
		}
		for(int i = 3;i < n - 1;i++){
			if(f[i] == 1 && c[i] == n){
				cout << (c[i - 1] - c[i - 2]) * (f[i + 1] - 1) + (n - c[i - 1]) * (f[i + 2] - f[i + 1]) << '\n';
				return ;
			}
		}
	}
	for(int i = 1;i < n;i++){
		int l = i;
		f[i] = 0,c[i] = 1;
		for(int r = i + 1;r <= n;r++){
			while(a[r] - a[l] > d) l++;
			if(l == r) break;
			f[r] = f[l] + 1,c[r] = c[l];
			if(f[l + 1] == f[l]) c[r] += c[l + 1];
			if(l + 2 < r && f[l + 2] == f[l]) c[r] += c[l + 2];
			c[r] = min(c[r],3LL);
			if(c[r] == 2) ans++;
		}
	}
	cout << ans << '\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> x >> t;
	while(t--) solve();
	return 0;
}

