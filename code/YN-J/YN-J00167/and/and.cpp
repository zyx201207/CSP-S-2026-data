#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 2e5 + 5;
int g[N];
int rem[N];

int dfs(int now,int nu){
	if (rem[nu] != 0)return rem[nu];
	int maxn = INT_MIN;
	if (now <= 1){
		for (int i = nu + 1;i <= n;i ++){
			return g[i];
		}
	}else{
		for (int i = nu+1;i <= n;i ++){
			int mx = max(maxn,(g[i] & dfs(m - 1,i)));
			rem[nu] = mx;
			return mx;
		}
	}

}

int main(void) {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		cin >> g[i];
	}
	int maxn = INT_MIN;
	for (int i = 1;i <= n;i ++){
		maxn = max(maxn,(g[i] & dfs(m - 1,i)));
	}
	cout<<maxn;

	return 0;
}
