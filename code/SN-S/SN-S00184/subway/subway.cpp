#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap {
int way[550][550];
signed tsa[550][500050];
void work() {
    //int tm = clock();
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >>q;
    vector<signed> w(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> w[i];
    }
    vector<vector<signed>> /*sub(n + 1, vector<int>()),*/ sta(m + 1, vector<signed>());
    //unordered_map<pair<int,int>, int> tsa;//subwayId, stationId
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; ++j) {
            int sti, tmi;
            cin >> sti >> tmi;
            // sub[i].push_back(sti);
            sta[sti].push_back(i);
            tsa[i][sti] = tmi;
        }
    }
    for (int i = 0; i < 505 ;++i) {
        for (int j = 0; j < 505; ++j) {
            way[i][j] = 1e15;
            if (i == j) {
                way[i][j] = 0;
            }
        }
    }
    way[0][0]=1e15;
    for (int i = 1; i <= m; ++i) {
        int len = sta[i].size();
        for (int x = 0; x < len; ++x) {
            for (int y = 0; y < len; ++y) {
                int ix = sta[i][x];
                int iy = sta[i][y];
                if (ix == iy) {
                    continue;
                }
                int tnow = tsa[ix][i] + tsa[iy][i];
                way[ix][iy] = min(way[ix][iy], tnow);
                way[iy][ix] = way[ix][iy];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for(int k = 1; k <= n; ++k) {
                way[i][k] = min(way[i][j] + way[j][k], way[i][k]);
                //cout << "!" << i << ' ' << j <<' '<< k << ' ' <<way[i][k] << endl;
                way[k][i] = way[i][k];
            }
        }
    }
    while (q--) {
        int x,y;
        cin >> x >> y;
        int ans = 1e15;
        for (int i = 0; i < sta[x].size(); ++i) {
            for (int j = 0; j < sta[y].size(); ++j) {
                signed ix = sta[x][i];
                signed iy = sta[y][j];
                ans=min(ans, way[ix][iy] + tsa[ix][x] + tsa[iy][y]);
                //cout << ix <<' ' << iy << endl;
                //cout << tsa[pair<int,int>(ix, x)] <<' ' <<tsa[pair<int,int>(iy, y)] << ' ' << way[ix][iy]<< endl;
            }
        }
        //cout << "1112121" << endl;
        // for (int i = 1; i <=3; i++) {
        //     for (int j = 1; j <= 3; j++) {
        //         //cout <<way[i][j] << ' ';
        //     }
        //     //cout << endl;
        // }
        cout << ans + w[x] + w[y] << endl;
    }
    //cerr << clock() - tm;
}
}
signed main() {
    freopen("subway.in", "r",stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    Qaaxaap::work();
    return 0;
}
