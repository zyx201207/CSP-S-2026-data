#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2E6 + 5;
long long x[MAXN];
int y[MAXN];
int z[MAXN];
long long vis[MAXN];

int n;
long long d;

long long get_once(int id){

    if(y[id] == y[id - 1]) return 0;
    return y[id] - y[id - 1] + (z[y[id]] = get_once(y[id]));

}

long long dfs(int id){

    if(id == n) return 0;
    if(x[id] + d < x[id + 1]) return 0;

    long long res(0);
    if(y[id] - id == 1){

        return (vis[y[id]] = dfs(y[id]));

    }else if(y[id] - id == 2){

        res = y[y[id] - 1] - y[id];
        if(z[y[y[id] - 1]] == -1 && y[y[id] - 1] != y[id]) z[y[y[id] - 1]] = get_once(y[y[id] - 1]);
        if(z[y[y[id] - 1]] != -1) res += z[y[y[id] - 1]];
        return res + (vis[y[id]] = dfs(y[id]));

    }else if(y[id] - id >= 3){

        res = y[y[id] - 1] - y[y[id] - 2];
        if(z[y[y[id] - 1]] == -1 && y[y[id] - 1] != z[y[y[id] - 2]]) z[y[y[id] - 1]] = get_once(y[y[id] - 1]);
        if(z[y[y[id] - 1]] != -1) res += z[y[y[id] - 1]];
        return res + (vis[y[id]] = dfs(y[id]));

    }

}

int s[MAXN];
int cnt[MAXN];

void serach(int id, int depth){

    if(depth < s[id]){
        s[id] = depth;
        cnt[id] = 1;
    }else if(depth == s[id]) cnt[id] ++;
    else return;

    for(int i = y[id]; i >= id + 1; i-- ){
        serach(i, depth + 1);
    }

}

void solve(){

    for(int i = 1; i <= n; i++ ) s[i] = 0x3f3f3f3f;
    long long ans(0);

    for(int i = 1; i <= n; i++ ){
        serach(i, 0);
        for(int j = i + 1; j <= n; j++ ){
            ans += cnt[j] == 2;
            s[i] = 0x3f3f3f3f;
            cnt[i] = -1;
        }
    }

    cout << ans << '\n';

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int t;
    cin >> t >> t;

    while(t--){

        cin >> n;
        cin >> d;

        for(int i = 1; i <= n; i++ ){
            cin >> x[i];
            vis[i] = -1;
            z[i] = -1;
        }
        for(int i = 1; i <= n; i++ ) y[i] = upper_bound(x + i, x + 1 + n, x[i] + d) - x - 1;



        long long ans(0);
        for(int i = 1; i <= n; i++ ){

            if(vis[i] == -1) vis[i] = dfs(i);
            ans += vis[i];

        }

        cout << ans << '\n';

    }

    return 0;
}
