
#include <bits/stdc++.h>
using namespace std;
int a[200005];
int n, m;
int ans = -0x3f;
void dfs(int id, int sl, int sum){
	if(id > n) return;
    if(sl == m) {
		cout << sum << endl;
        ans = max(ans, sum);
        return ;
    }
    if(sl == 0) sum = a[id];
    dfs(id + 1, sl + 1, sum & a[id]);
    if(sl == 0) sum = 0;
    dfs(id + 1, sl, sum);
    
}
int main(){
	//freopen("and.in", "r", stdin);
	//freopen("and.out", "w", stdout);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dfs(1, 0, 0);
    cout << ans;
    return 0;
}
