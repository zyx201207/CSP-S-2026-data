#include<bits/stdc++.h>
using namespace std;
int a[200005], ans[200005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		ans[a[i]] = max(ans[a[i]], i);
	}
	for(int i = 1; i <= m; i++){
		if(ans[i]) cout << ans[i] << ' ';
	}
	return 0;
}

