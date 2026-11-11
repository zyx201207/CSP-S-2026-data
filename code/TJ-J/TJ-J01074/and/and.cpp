#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200005],c[200005];
void dfs(int step) {
	if (step>=n) {
		int cnt=0,t=(1<<20)-1;
		for (int i=0;i<step;i++) {
			if (c[i]) {
				cnt++;
				t=t&a[i];
			}
		}
		if (cnt==m) {
			ans = max(ans,t);
		}
		return ;
	}
	for (int i=0;i<=1;i++) {
		c[step]=i;
		dfs(step+1);
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=0;i<n;i++) {
		cin >> a[i];
	}
	dfs(0);
	cout << ans;
	return 0;
}
