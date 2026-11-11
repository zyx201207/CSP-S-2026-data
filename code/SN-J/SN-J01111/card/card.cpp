#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+9, M = 3e5+9;
int n, m, a[N], ans[M];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		if(a[i]!=a[i+1]) ans[a[i]] = i;
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
