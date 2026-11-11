#include <bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N = 5e5 + 10;
const int inf = 0x3f3f3f3f;
struct node {
    int time;
    int snum;
    int num;
};
int c[N];
vector<node> g[N];
vector<PII> sub[N];
int ans = inf;
void dfs(int x,int step,int ends) {
    if (x == ends) {
        ans = min(ans,step);
        return;
    }
    for (node i : g[x]) {
        if (i.num == 0) dfs(sub[i.snum][1].first,step + i.time + sub[i.snum][1].second,ends);
    }
}
int solve(int x,int y) {
    ans = 0;
    cout << ans + c[x] + c[y] << '\n';
}
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int tmp,n,m,d,q;
    cin >> tmp >> n >> m >> d >> q;
    for (int i=1;i<=m;++i) cin >> c[i];
    for (int i=1;i<=n;++i) {
        int k;
        cin >> k;
        for (int j=1;j<=k;++j) {
            int x,y;
            cin >> x >> y;
            sub[i].push_back({x,y});
            g[sub[i][j].first].push_back({sub[i][j].second,i,j});
        }
    }
    for (int i=1;i<=q;++i) {
        int x,y;
        cin >> x >> y;
        cout << c[x] + c[y] << '\n';
     }
    return 0;
}
//AFO
