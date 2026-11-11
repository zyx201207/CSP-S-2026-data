#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 15;
int c, t;
int n, d;
int a[N];
int k[N];
int ans[N][N][N];
struct node {
    int pos, val;
};
void dfs(int dep) {
    if(dep == n + 1) {
        node b[N];
        for(int i = 0; i <= n; i++)
            b[i] = {0, 0};
        int l = 0;
        for(int i = 1; i <= n; i++)
            if(k[i])
                b[++l].pos = i, b[l].val = a[i];
        bool f = 0;
        for(int i = 2; i <= l; i++) 
            if(b[i].val - b[i - 1].val > d) {
                f = 1; break;
            }
        if(!f)
            ans[b[1].pos][b[l].pos][l]++;
        return ;
    }
    k[dep] = 1;
    dfs(dep + 1);
    k[dep] = 0;
    dfs(dep + 1);
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        memset(k, 0, sizeof k);
        memset(ans, 0, sizeof ans);
        cin >> n >> d;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        dfs(1);
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                for(int z = 1; z <= n; z++) {
                    if(ans[i][j][z] >= 1) {
                        if(ans[i][j][z] == 2)
                            sum++;
                        else
                            break;
                    }
                }
            }
        }
        cout << sum << '\n';
    }
    return 0;
}