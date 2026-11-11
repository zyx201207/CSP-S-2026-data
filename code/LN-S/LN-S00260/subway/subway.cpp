#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX = 5e5 + 10,RMAX=1e9;
ll mp[500][500],w[MAX];

struct node{
    ll cnt=0,t[20],id[20];
}sub[MAX];

void Floyd(ll t){
    for (ll i=1;i<=t;i++)
        for (ll j=1;j<=t;j++)
            for (ll k=j;k<=t;k++){
                mp[j][k] = min(mp[j][k],mp[j][i]+mp[i][k]);
                mp[k][j] = min(mp[k][j],mp[k][i]+mp[i][j]);
            }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ll c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    memset(mp,0x3f,sizeof(mp));
    ll t_p[n][m];
    for (ll i=1;i<=n;i++) mp[i][i] = 0;
    for (ll i=1;i<=m;i++) cin >> w[i];
    for (ll i=1;i<=n;i++){
        ll k,a,t;
        cin >> k;
        ll a_p[k];
        for (ll j=0;j<k;j++){
            cin >> a >> t;
            a_p[j] = a;
            t_p[i][a] = t;
            sub[a].cnt += 1;
            sub[a].t[sub[a].cnt] = t;
            sub[a].id[sub[a].cnt] = i;
            for (ll p=1;p<sub[a].cnt;p++){
                mp[i][sub[a].id[p]] = min(mp[i][sub[a].id[p]],t + sub[a].t[p]);
                mp[sub[a].id[p]][i] = mp[i][sub[a].id[p]];
            }
        }
    }
    Floyd(n);
    for (ll i=0;i<q;i++){
        ll x,y,res=RMAX;
        cin >> x >> y;
        for (ll i=1;i<=sub[x].cnt;i++){
            for (ll j=1;j<=sub[y].cnt;j++){
                if (mp[sub[x].id[i]][sub[y].id[j]] + t_p[sub[x].id[i]][x] + t_p[sub[y].id[j]][y] < res) res = mp[sub[x].id[i]][sub[y].id[j]] + t_p[sub[x].id[i]][x] + t_p[sub[y].id[j]][y];
            }
        }
        cout << w[x] + w[y] + res << '\n';
    }

    return 0;
}
