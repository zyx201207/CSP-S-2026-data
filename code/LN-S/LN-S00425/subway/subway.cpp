#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,w[500005],a[505][50005],t[505][50005],k[505],u,v;
    vector <int> x[50005];
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++)
        cin >> w[i];
    for (int i = 1;i <= n;i++){
        cin >> k[i];
        for (int j = 1;j <= k[i];j++){
            cin >> a[i][j] >> t[i][j];
            x[a[i][j]].push_back(i);
        }
    }
    while (q--){
        cin >> u >> v;
        cout << w[u]+w[v]+t[x[u][0]][0]+t[x[v][0]][0] << endl;
    }
    return 0;
}
