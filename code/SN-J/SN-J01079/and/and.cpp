#include<bits/stdc++.h>
using namespace std;
long long n, m, a[200005], maxn, f[200005];
void dfs(long long num, long long o){
	if(o == m){
		maxn = max(maxn, num);
		return;
	}
	for(int i = 0; i < n; i ++){
		if(f[i] == 1) continue;
		f[i] = 1;
		dfs((num & a[i]), o + 1);
		f[i] = 0;
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i ++){
		f[i] = 1;
		dfs(a[i], 1);
		f[i] = 0;
	}
	cout << maxn;
	return 0;
}


