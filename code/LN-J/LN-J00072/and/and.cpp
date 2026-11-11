#include <bits/stdc++.h>

using namespace std;

int n , m;
int a[200005];
bool vis[200005];
int max_ans = INT_MIN;
void dfs (int cnt , int now_val) {
    if (cnt == m) {
        max_ans = max(max_ans , now_val);
        return ;
    }

    for (int i = 1; i <= n; i ++) {

        if (!vis[i]) {
            vis[i] = true;
            if (cnt > 0) {
                dfs(cnt + 1 , now_val & a[i]);
            } else if (cnt == 0) {
                dfs(cnt + 1 , a[i]);
            }
            vis[i] = false;
        }
    }
    return ;
}
int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    memset(vis , false , sizeof(vis));

    dfs(0 , 0);
    cout << max_ans << endl;
    return 0;
}
