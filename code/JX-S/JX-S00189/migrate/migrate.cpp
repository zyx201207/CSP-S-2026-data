#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 10;
int a[N];
bool vis[N];
int c, t;
int n, d;
vector<vector<int>> g(N);
vector<vector<int>> dis(N);

void dfs(int i, int cnt){
    cout << 1;
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(i != j){
                    if(abs(a[i] - a[j]) <= d){
                        g[i].push_back(j);
                    }
                }
            }
        }
        for(int i = 1;i <= n;i++){
            dfs(i, 0);
            for(int j = i + 1;j <= n;j++){
                
            }
        }
    }
    return 0;
}
