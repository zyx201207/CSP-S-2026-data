#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 8;
int n, m;
int a[N], ans[N];
int vis[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	
	
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	
	if(n >= 5000) {
		for(int i=1; i<=n; i++) {
			ans[a[i]]++;
		}
		for(int i=1; i<=m; i++) {
			cout<<ans[i]<<' ';
		}
		return 0;
	}
	
	for(int _=1; _<=n; _++) {
		for(int i=1; i<=n; i++) {
			vis[i] = 0;
		}
		for(int i=_; i<=n; i++) {
			vis[a[i]]++;
			if(vis[a[i]] > 1) {
				for(int j=i; vis[a[i]] >= 1; j--) {
					vis[a[j]]--;
				}
				vis[a[i]]++;
			}
		}
		for(int i=1; i<=n; i++) {
			if(vis[i] == 1) {
				ans[i]++;
			}
		}
	}
	
//	for(int i=1; i<=n; i++) {
//		cin>>a[i];
//		if(vis[a[i]] >= 1) {
//			ans[a[i]]++;
//		}else {
//			vis[a[i]]++;
//			ans[a[i]]++;
//		}
//		
//	}
//	
//	ans[a[n]] = n;
////	for(int i=n; i>=1; i--) {
////		if(vis[])
////	}
	for(int i=1; i<=m; i++) {
		cout<<ans[i]<<' ';
	}
	return 0;
}
