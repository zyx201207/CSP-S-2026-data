#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 9;
int n,m,d,ti,ans;
int mapp[5 * MAXN],way[501][10001];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i ++) cin >> w[i];
    memset(mapp + 1,1e9,m + 1);
    for(int i = 1;i <= n;i ++){
        int k;
        cin >> k;
        for(int j = 1;j <= k;j ++){
            int aa,tt;
            cin >> aa >> tt;
            mapp[aa] = min(mapp[aa],tt);
            way[j][aa] = 1;
        }
    }
    for(int i = 1; i <= q;i ++){
        int x,y;
        cin >> x >> y;
        for(int j = 1;j <= n;j ++){
                int ans = 0;
                int pre = x;
            for(int z = 1;z <= m; z++){
                if(way[j][z] && pre != y){
                    ans += mapp[z] + mapp[pre];
                    pre = z;
                }
            }
        }
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}
