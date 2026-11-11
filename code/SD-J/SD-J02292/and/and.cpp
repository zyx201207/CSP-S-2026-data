#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ans;
const int MAX_n = 200010;
bool vis[MAX_n];
int a[MAX_n];
void dfs(int step,int i_start) {
	if(step == m) {
		int lans = 0;
		bool flag = 0;
		for(int i = 1;i <= n;i++) {
			if(vis[i] && !flag) {
				lans = a[i];
				flag = 1;
			} else if(vis[i]) lans = lans & a[i];
		}
		ans = max(lans, ans);
	} else {
		for(int i = i_start;i <= n;i++) {
			vis[i] = 1;
			dfs(step + 1, i + 1);
			vis[i] = 0;
		}
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	dfs(0, 1);
	cout << ans;
	return 0;
}

