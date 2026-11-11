#include<bits/stdc++.h>
#define int long long
#define QwQ 0
#define debug cout << "!!!" << "\n";
using namespace std;
int n, m;
int a[500010];
int ans[300010];
int f[500010];
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = n; i >= 1; i--){
		if(ans[a[i]] == 0)	ans[a[i]] = i;
	}
	for(int i = 1; i <= m; i++){
		if(i == m)	cout << ans[i];
		else cout << ans[i] << ' ';
	}
	cout << '\n';
	return QwQ;
}