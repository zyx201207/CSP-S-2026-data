#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 5e5+5;


int c, n, m, d, q;
LL ann[505][505];
int amw[N];
int anidx[505], ank[505][N], anmk[505][N]; 

void solve(){

    int xr, yr;
    LL ans = 1e18;

    LL sumt = 0;
    cin >> xr >> yr;

    for(int i = 1; i <= n; i ++){
        for(int j = i; j <= n; j ++){
            sumt = 0;
            if(anmk[i][xr] != 0 && anmk[j][yr] != 0){
                sumt += amw[xr];
                sumt += anmk[i][xr];
                sumt += ann[i][j];
                sumt += anmk[j][yr];
                sumt += amw[yr];

                ans = min(ans,  sumt);
            }else if(anmk[i][yr] != 0 && anmk[j][xr] != 0){
                sumt += amw[yr];
                sumt += anmk[i][yr];
                sumt += ann[i][j];
                sumt += anmk[j][xr];
                sumt += amw[xr];

                ans = min(ans, sumt);
            }
        }
    }
    cout << ans << '\n';
}   

int main(){

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(ann, 0x3f, sizeof(ann));

    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i ++)cin >> amw[i];

    for(int i = 1; i <= n; i ++){
        cin >> anidx[i];
        for(int j = 1; j <= anidx[i]; j ++){
            int tx, ty;
            cin >> tx >> ty;

            ank[i][j] = tx;
            anmk[i][tx] = ty;
        }
        sort(ank[i] + 1, ank[i] + anidx[i] + 1);
    }

    for(int i = 1; i <= n; i ++){
        for(int j = i; j <= n; j ++){
            if(i == j){
                ann[i][j] = 0;
                continue;
            }
            //find all point in (i && j)
            for(int k = 1; k <= anidx[i]; k ++){
                int state = ank[i][k];
                int cost = anmk[i][state];

                if(anmk[j][state] != 0){
                    ann[i][j] = min(ann[i][j], (LL)(anmk[i][state] + anmk[j][state])); 
                    ann[j][i] = ann[i][j];
                }
            }
        }
    }

    // for(int i = 1; i <= n; i ++){
    //     for(int j = 1; j <= n; j ++){
    //         cout << ann[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    for(int k = 1; k <= n; k ++){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(ann[i][k] + ann[j][k] <= ann[i][j]){
                    ann[i][j] = ann[i][k] + ann[j][k];
                }
            }
        }
    }

    // for(int i = 1; i <= n; i ++){
    //     for(int j = 1; j <= n; j ++){
    //         cout << ann[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    while(q--)solve();

    return 0;
}