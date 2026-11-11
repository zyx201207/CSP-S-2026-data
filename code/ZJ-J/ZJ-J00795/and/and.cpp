#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 5;
int n, m, a[MAX];
int ans, box[MAX], vis[MAX];
void dfs(int dep, int st){
	if(dep == m + 1){
		int tmp = box[1];
		cout << tmp << " ";
		for(int i = 2; i < dep; i++){
			cout << box[i] << " ";
			tmp &= box[i];
		}
		cout << "\n" << tmp << "\n";
		ans = max(ans, tmp);
	}
	for(int i = st; i <= n; i++){
		if(vis[i] == 0){
			vis[i] = 1;
			box[dep] = a[i];
			dfs(dep + 1, i);
			vis[i] = 0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1, 1);
	cout << ans;
}