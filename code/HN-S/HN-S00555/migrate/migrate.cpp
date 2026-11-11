#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e6+100; 
int n,d;
int a[MAXN],lst[MAXN],pre[MAXN],vis[MAXN];
int ans;
void solve() {
	ans=0;
	cin >> n >> d;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	} 
	for (int i=1,j=1; i<=n; i++) {
		while (j<n && a[j+1]-a[i]<=d) {
			j++;
		}
		lst[i]=j;
	}
	for (int i=n,j=n; i>=1; i--) {
		while (j>1 && a[i]-a[j-1]<=d) {
			j--;
		}
		pre[i]=j;
	} 
	for (int i=1; i<=n; i++) {
		fill(vis,vis+n+1,0);
		for (int o=lst[i]; o!=lst[o]; o=lst[o]) { 
			for (int j=o+1; j<=lst[o]; j++) {
				if (o-pre[j]>1) {
					vis[j]=2;
				} else if (o-pre[j]==1){
					vis[j]=1+vis[pre[j]];
				} else {
					vis[j]+=vis[pre[j]];
				}
				ans+=vis[j]==1;
			}
		}
	}
 	cout << ans << "\n";
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
	int C,T;
	cin >> C >> T;
	while (T--) {
		solve();
	} 
	return 0;
}
/*
0 1
6 2
-4 -3 -2 -1 3 6

*/
