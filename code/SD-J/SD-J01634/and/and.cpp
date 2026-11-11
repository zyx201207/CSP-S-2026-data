#include<bits/stdc++.h>
using namespace std;

int n,m;

long long a[10005];
int ans;
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	
	

	
	if(m == 2){
		
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				int ss = (a[i] & a[j]);
				ans = max(ans, ss);
				
			}
		}
		
		
		cout << ans;
		return 0;
		
	}
	if(m == 1) {
		cout << 0;
		return 0;
	}
	
	if(m == n) {
		ans = a[1];
		for(int i = 1; i <= n; i++) {
			ans = a[i] & ans;
		}
		cout << ans;
		return 0;
	}
	
	bool bb = false;
	
	for(int i = 1; i <= n; i++){
		if(a[i] != (i - 1)) {
			bb = true;
		}
		
		
	}
	ans = a[n];
	if(!bb) {
		ans = a[n];
		while (m--) {
			n--;
			ans = a[n] & ans;
			
		}
		
	}cout << ans;
	return 0;
}



































