#include <bits/stdc++.h>
using namespace std;
#define str string
#define ll long long
void io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int c,n,m,d,q;
int w[500010];
int a[5010][5010];
int t[5010][5010];
int x,y,ans;
int main() {
    io();
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1; i <= m; i++) cin>>w[i];
    for(int i = 1; i <= n; i++) {
        int k;
        cin>>k;
        for(int j = 1; j <= k; j++) {
            int aa,tt;
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i = 1; i <= q; i++) {
        cin>>x>>y;
        ans = 0;
        ans = ans + w[x] + w[y] + t[x][x];
        ans = ans + t[2][y] + t[2][3];
        ans = ans + t[1][2];
        cout<<ans<<'\n';
    }

    return 0;
}
