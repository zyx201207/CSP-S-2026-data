#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
const int maxn = 2e5 + 10;
int l[maxn]; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	for(int i = 0; i < n; i++){
		cin>>l[i];
	}
	sort(l, l + n);
	reverse(l, l + n);
	int ans = l[0];
	for(int i = 1; i < m; i++){
		ans &= l[i];
	} 
	cout<<ans;
	return 0;
}
