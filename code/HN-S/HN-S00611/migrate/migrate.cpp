#include<bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

long long d, x[N];
int c, t, n, p[N], f[N], s[N], flag[N];

void Solve(){
    cin >> n >> d;
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++){
        p[i] = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
    }
    int ans = 0;
    for(int r = 1; r <= n; r++){
        f[r] = 0;
        for(int i = r - 1; i >= 1; i--){
            f[i] = -1;
        }
        for(int i = 1; i <= r; i++) s[i] = 0;
        for(int i = r - 1; i >= 1; i--){
            if(p[i] >= r) f[i] = 1;
            else{
                if(f[p[i]] == -1) continue;
                f[i] = f[p[i]] + 1;
            }
        }
        flag[r] = 0;
        for(int i = r - 1; i >= 1; i--){
            if(p[i] >= i + 2 && i + 2 <= r){
                int now = min(r, p[i]);
                if(f[now] == f[now - 1]){
                    flag[i] = 1;
                    if(p[i] >= i + 3 && f[now] == f[now - 2] && i + 3 <= r){
                        flag[i] = 2;
                    }
                }
                else{
                    flag[i] = 0;
                }
            }
            else{
                flag[i] = 0;
            }
        }
        for(int i = r; i >= 1; i--){
            if(f[i] == -1) continue;
            s[i] = s[min(p[i], r)] + flag[i];
            ans += (s[i] == 1);
        }
    }
    cout << ans << '\n';
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    for(cin >> c >> t; t--; Solve()){
    }
    return 0;
}
/*
0 1
6 2
-4 -3 -2 -1 3 6
*/
