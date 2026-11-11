#include<bits/stdc++.h>
#define ll long long
//rp++
//2 ^ k-1 = 111111111(2)
// 01 backpack
using namespace std;

const int N = 2e5 + 10;
int n, m, a[N], v[N], f[N], ans, is_b;

void dfs(int dep){
	if(dep == m + 1){
		int sum = f[1];
		for(int i = 2;i <= m;i ++)
			sum &= f[i];
		ans = max(ans, sum);
		return;
	}
	for(int i = 1;i <= n;i ++){
		if(!v[i]){
			v[i] = 1;
			f[dep] = a[i];
			dfs(dep + 1);
			v[i] = 0;
		}
	}
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		if(a[i] != i - 1) is_b;
	}
	dfs(1);
	cout << ans;
	return 0;
}

