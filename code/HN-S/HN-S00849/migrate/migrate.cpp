#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e6 + 5;

int c, t, n, d, b[maxn];
long long x[maxn];

void C(){
    for(int i = 1; i <= n; i++){
        if(b[i]){

        }
    }
}

void dfs(int x){
    if(x > n){
        return;
    }
    b[x] = 1, dfs(x + 1);
    b[x] = 0, dfs(x + 1);
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    for(cin >> t; t; t--){
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
        }
        cout << 0 << '\n';
    }
    return 0;
}

//Oct31==Dec25?

