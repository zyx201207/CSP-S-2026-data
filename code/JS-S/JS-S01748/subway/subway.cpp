#include <bits/stdc++.h>
using namespace std;

int w[500001],t[501][500001];
bool a[501][500001];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,jj;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++){
        int k_;
        cin >> k_;
        for(int j = 1;j <= k_;j++){
            int sr;
            cin >> sr >> t[i][j];
            a[i][sr] = 1;
            for(int l = 1;l < i;l++){
                if(a[l][sr]){
                    jj = sr;
                }
            }
        }
    }
    for(int i = 1;i <= q;i++){
        bool hh = true;
        int x,y,ans = w[x]+w[y];
        cin >> x >> y;
        for(int j = 1;j <= n;j++){
            if(a[j][x] && a[j][y]){
                cout << w[x]+w[y]+t[j][x]+t[j][y] << endl;
                hh = false;
                break;
            }
        }
        if(hh){
            for(int j = 1;j <= n;j++){
                if(a[j][x]) ans+=t[j][x]+t[j][jj];
                if(a[j][y]) ans+=t[j][y]+t[j][jj];
            }
            cout << ans << endl;
        }
    }
    return 0;
}

