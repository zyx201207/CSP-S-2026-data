#include<bits/stdc++.h>
using namespace std;
long long n, d;
long long x[2000005]; // ccf jnb n^3 out 2000000
bool okay(int i, int j){
	return x[j]-x[i] <= d;
}
long long f[2000005];
long long N[2000005];
int main(){
	freopen("migrate4.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c, t; cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		int ans = 0;
		for(int j=1;j<=n;j++){
			// j ~ k calcute
			memset(f, 0x3f, sizeof f);
			memset(N, 0, sizeof N);
			f[j]=0; N[j]=1;
			for(int k=1;k<=n;k++){
				for(int l=j;l<k;l++){
					if(!okay(l, k)) continue;
					f[k] = min(f[l]+1ll, f[k]);
				}
				for(int l=j;l<k;l++){
					if(!okay(l, k) || f[k] != f[l]+1) continue;
					N[k]+=N[l];
				}
				if(N[k] == 2) ans++;
			}
		}
		cout << ans << endl;
	}
}
/*
PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    
PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    
PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    
PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    
PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    
PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    
PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    
PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    
PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    
PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    
PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    
PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    
PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    
PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    
PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    
PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    
PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    
PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    
PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    
PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    PdLZQo1ZOs== PdLZQo1ZOs==    
*/