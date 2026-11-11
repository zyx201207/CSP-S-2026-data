#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#define ll long long
#define MAXN 1e10
using namespace std;
ll c,n,m,d,q,w[500005],f[600][600],x,y;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    for(ll i = 0;i <= 500;i++){
        for(ll j = 0;j <= 500;j++){
            if(i == j)
                f[i][j] = 0;
            else
                f[i][j] = MAXN;
        }
    }
    cin >> c >> n >> m >> d >> q;
    for(ll i = 1;i <= m;i++)
        cin >> w[i];
    for(ll i = 1;i <= n;i++){
        ll k = 0,a,b;
        vector <ll> sub,tim;
        cin >> k;
        for(ll j = 1;j <= k;j++){
            cin >> a >> b;
            sub.push_back(a);
            tim.push_back(b);
        }
        for(ll l = 0;l < (ll)sub.size();l++){
            //cout << sub[l] << " " << tim[l] << endl;
        }
        for(ll l = 0;l < (ll)sub.size();l++){
            for(ll r = l+1;r < (ll)sub.size();r++){
                //cout << f[sub[l]][sub[r]] << "  " << tim[l] + tim[r] << endl;
                f[sub[l]][sub[r]] = min(f[sub[l]][sub[r]],tim[l] + tim[r]);
                f[sub[r]][sub[l]] = f[sub[l]][sub[r]];
            }
        }
    }
    
    for(ll k = 1;k <= n;k++){
        bool b = false;
        for(ll i = 1;i <= n;i++){
            for(ll j = i+1;j <= n;j++){
                for(ll p = j+1;p <= n;p++){
                    if(f[i][j] + f[j][p] <= f[i][p]){
                        f[i][p] = f[i][j] + f[j][p];
                        f[p][i] = f[i][p];
                        b = true;
                    }
                    //f[i][p] = min(f[i][p],f[i][j] + f[j][p]);
                    //f[p][i] = f[i][p];
                }
            }
        }
        if(!b){
            break;
        }
    }
    
    
    /*for(ll i = 1;i <= 10;i++){
        for(ll j = 1;j <= 10;j++)
            printf("%3lld ",f[i][j]);
            //cout << f[i][j] << " ";
        cout << endl;
    }*/

    for(ll i = 1;i <= q;i++){
        cin >> x >> y;
        ll ans = f[x][y];
        for(ll i = 1;i <= n;i++){
            ans = min(ans,f[x][i]+f[i][y]);
        }
        ans = ans + w[x] + w[y];
        cout << ans << endl;
    }
    return 0;
}
