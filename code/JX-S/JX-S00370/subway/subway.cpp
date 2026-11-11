#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500 + 10;
const int M = 5e5 + 10;
const int K = 5e4 + 10;
int c,n,m,d,q,w[M],k[N],a[N][K],t[N][K];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> k[i];
        for(int j = 1;j <= k[i];j++){
            cin >> a[i][j] >> t[i][j];
        }
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        int ans = w[x] + w[y];
        for(int i = x;i <= y;i++){
            for(int j = x;j <= y;j++){
                if(i <= j){
                    ans += t[i][j];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
