#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
int n, m;
const int N = 2e5+5;
ll a[N];
bool vis[N];
ll ans;
void dfs(int d, ll cur) {
	if(d>m) {
		ans=max(ans, cur);
		return;
	}
	if(cur<=ans) return;
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			vis[i]=true;
			dfs(d+1, cur&a[i]);
			vis[i]=false;
		}
	}
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1, INT_MAX);
	cout<<ans<<'\n';
    return 0;
}
