#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5E5 + 5;
const int MAXM = 3E5 + 5;

struct Node{
    int u, w;
};

vector<int> g[MAXN];
int a[MAXN];
int vis[MAXN];
long long res[MAXN];

int ans[MAXN];

long long dfs(int u){

    long long sum(0);
    for(auto x : g[u]){
        sum += dfs(x);
    }

    ans[u] += sum + res[u];
    return sum + res[u];

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    for(int i = n; i >= 1; i-- ) cin >> a[i];
    for(int i = 1; i <= n; i++ ){
        if(!vis[a[i]]){

            vis[a[i]] = i;
            g[a[i - 1]].push_back(a[i]);
            res[a[i]] = 1;

        }else{

            res[a[i]]++;

        }

    }

    dfs(0);

    for(int i = 1; i <= m; i++ ) cout << ans[i] << ' ';
    return 0;
}

