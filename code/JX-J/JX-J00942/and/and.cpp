#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

int n, m;
int a[maxn];
int b[maxn];
bool vis[maxn];
int now, ans;

void dfs(int k){
    if(k > m){
        now = b[1];
        for(int i = 1; i <= m; i++)
            now = (now & b[i]);
        ans = max(now, ans);
        return;
    }

    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;

        b[k] = a[i];
        vis[i] = true;

        dfs(k + 1);

        b[k] = 0;
        vis[i] = false;
    }
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    dfs(1);

    cout << ans;
    return 0;
}
