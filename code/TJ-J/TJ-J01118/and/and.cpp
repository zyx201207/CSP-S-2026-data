#include<bits/stdc++.h>
using namespace std;
int n, m; 
int a[200010];
int f[10010][10010];
int ans = a[1];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout); 
	int mx = -1;
	int mn = 1e8;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	int cmx = -1;
	bool f = 1;
	for(int i = 1; i <= n; i++){
		if(a[i] == mx && f == 1){
			f = 0;
			continue;
		}
		cmx = max(cmx, a[i]);
	}
	if(m == 1){
		printf("%d", mx);
		return 0;
	}
	f = 1;
	for(int i = 2; i <= n; i++){
		ans &= a[i];
	}
	if(m == n){
		printf("%d", ans);
		return 0;
	}
	ans = a[1];
	if(m == n - 1){
		for(int i = 1; i <= n; i++){
			if(a[i] == mn && f == 1){
				f = 0;
				continue;
			}
			ans &= a[i];
		}
		printf("%lld", ans);
		return 0;
	}
	if(m == 2){
		ans = mx & cmx;
		printf("%lld", ans);
		return 0;
	}
	return 0;
} 
