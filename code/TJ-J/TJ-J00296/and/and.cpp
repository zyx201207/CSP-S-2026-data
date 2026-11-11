#include<bits/stdc++.h>
#define int unsigned long long 
using namespace std;
const int N = 220000;
int n, m, a[N], ans = 0; 

signed main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for(int i=1; i<=n; ++i) cin >> a[i];
	sort(a+1, a+1+n);
	
	if(m==1){
		cout << a[n];
	}
	else if(m==2){
		for(int i=1; i<=n; ++i){
			for(int j=i+1; j<=n; ++j){
				ans = max(ans, ((a[i]) & (a[j])) );
			}
		}
		cout << ans;
	}
	else if(m==n){
		for(int i=1; i<=n; ++i) ans = (a[i] & ans);
		cout << ans;
	}else if(m==n-1){
		for(int i=1; i<=n; ++i){
			int tmp = 0;
			for(int j=1; j<=n; ++j){
				if(i==j) continue;
				tmp = (a[i] & tmp);
			}
			ans = max(ans, tmp);
			cout << ans;
		}
	}
//	for(int i=1; i<=m; ++m){
//		
//	}
	
	return 0;
}
