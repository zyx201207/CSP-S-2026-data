#include <bits/stdc++.h>
using namespace std;

int n, m, a[200005], maxn;
void dfs(int step, int k, int ans){
	if (ans<=maxn) return;
	if (k>m) return;
	if (step>n||k==m){
		if (k!=m) return;
		maxn=max(maxn, ans);
		return;
	}
	dfs(step+1, k+1, ans&a[step]);
	dfs(step+1, k, ans);
}
			
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	dfs(1, 0, 2147483647);
	cout << maxn << endl;
	return 0;
}
