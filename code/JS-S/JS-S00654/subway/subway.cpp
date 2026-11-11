#include <iostream>
#include <vector>
#include <cstring>
#define masm 500010
#define masn 510
#define int long long
using namespace std;

int c, n, m, d, q;
int w[masm];
int k[masn];
int t[masn][masm];
vector<int> line[masm]; // line[x]: station x's line

int g[masn][masn]; // graph of lines (no direction)

signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;i++)
        cin >> w[i];
    for (int i=1;i<=n;i++){ // O(m)
        cin >> k[i];
        for (int j=1;j<=k[i];j++){
            int s, time; cin >> s >> time;
            t[i][s]=time;
            line[s].push_back(i);
        }
    }

    // for (int i=1;i<=m;i++){
    //     cout << "station " << i << " :";
    //     for (auto l:line[i])
    //         cout << l << " ";
    //     cout << endl;
    // }

    memset(g, 0x3f, sizeof g);
    for (int k=1;k<=m;k++){ // build graph O(m*20^2)
        for (auto i:line[k])
            for (auto j:line[k]){
                if (i==j) g[i][j]=0;
                else g[i][j]=g[j][i]=min(g[i][j], t[i][k]+t[j][k]);
            }
    }

    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=n;j++)
    //         cout << g[i][j] << " ";
    //     cout << endl;
    // }

    // floyd => all shortest path O(n^3), 1.25*10^8
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (i==j) continue;
                g[i][j]=g[j][i]=min(g[i][j], g[i][k]+g[k][j]);
            }
        }
    }

    // for (int i=1;i<=n;i++){
    //     for (int j=1;j<=n;j++)
    //         cout << g[i][j] << " ";
    //     cout << endl;
    // }

    while (q--){  // O(q*20^2)
        int x, y; cin >> x >> y;
        int ans=0x7fffffffffffffff; // maybe inf

        for (auto i:line[x])
            for (auto j:line[y]){
                ans=min(ans, g[i][j]+t[i][x]+t[j][y]);
                // cout << i << " " << x << " " << j << " " << y << endl;
            }
        
        ans+=w[x]+w[y];

        cout << ans << endl;
    }


    return 0;
}


/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


*/