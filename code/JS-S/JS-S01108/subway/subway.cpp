#include <bits/stdc++.h>
#define ll long long
#define MAXN 505
#define INF 4000000000000000007ll
#define MOD 998244353
using namespace std;

ll ID,n,m,D,q;
ll w[500005],k[MAXN];
ll d[MAXN][MAXN],t[MAXN][500005];
vector<ll> a[MAXN],b[500005];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>ID>>n>>m>>D>>q;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            d[i][j] = d[j][i] = INF;
        }
    }

    for(int i = 1; i <= m; i++){
        cin>>w[i];
    }
    for(int i = 1; i <= n; i++){
        cin>>k[i];
        for(int j = 1; j <= k[i]; j++){
            ll tar;
            cin>>tar;
            a[i].push_back(tar);
            cin>>t[i][tar];
            for(int x : b[tar]){
                d[i][x] = d[x][i] = min(d[i][x], t[i][tar] + t[x][tar]);
            }
            b[tar].push_back(i);
        }
    }

    for(int z = 1; z <= n; z++){
        for(int x = 1; x <= n; x++){
            if(x == z)continue;
            for(int y = 1; y < x; y++){
                if(y == z)continue;
                d[x][y] = d[y][x] = min(d[x][y], d[x][z] + d[z][y]);
            }
        }
    }

    while(q--){
        ll x,y;
        cin>>x>>y;
        ll ans = INF;
        for(int i : b[x]){
            for(int j : b[y]){
                ans = min(ans, t[i][x] + d[i][j] + t[j][y]);
            }
        }
        ans += w[x] + w[y];
        cout<<ans<<"\n";
    }
    return 0;
}
