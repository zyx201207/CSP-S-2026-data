#include<bits/stdc++.h>
using namespace std;


int n,m,a[200005],fans = -1e9;
void dfs(int x,int step,int ans) {
	if(step == 3) {
		fans = max(ans,fans);
		return;
	}
	for(int i = x + 1; i <= n - step + 3; ++i) {
		dfs(i,step + 1,ans & a[i]);
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 1; i <= n - 3; ++i) {
		dfs(i,1,-1);
	}

	cout << fans;
	return 0;
}

