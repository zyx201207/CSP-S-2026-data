#include<bits/stdc++.h>
#define fast (ios::sync_with_stdio(0),cin.tie(0),cout.tie(0))
#define ll long long
#define ld long double
#define ull unsigned long long
#define maxm 500005
#define maxn 505
using namespace std;
ll c,n,m,d,q;
vector<pair<ll,ll>> a[maxm];
ll w[maxm];
ll dis[maxn][maxn];
signed main(){
    fast;
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++)cin>>w[i];
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(i!=j)dis[i][j]=3e18;
        }
    }
    for(ll i=1;i<=n;i++){
        ll k;cin>>k;
        for(ll j=1;j<=k;j++){
            ll p,t;cin>>p>>t;
            a[p].push_back({i,t});
        }
    }
    /*for(ll i=1;i<=m;i++){
        for(auto x:a[i])cout<<x.first<<" "<<x.second<<"     ";
        cout<<"\n";
    }*/
    for(ll x=1;x<=m;x++){
        ll sum=a[x].size();
        for(ll i=0;i<sum;i++){
            for(ll j=0;j<sum;j++){
                if(i!=j){
                   dis[a[x][i].first][a[x][j].first]=min(dis[a[x][i].first][a[x][j].first],a[x][i].second+a[x][j].second);
                }
            }
        }
    }
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    /*for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cout << dis[i][j] << " ";
        }
        cout << "\n";
    }*/
    for(ll v=1;v<=q;v++){
        ll x,y;cin>>x>>y;
        ll ans=3e18,ss1=a[x].size(),ss2=a[y].size();
        for(ll i=0;i<ss1;i++){
            for(ll j=0;j<ss2;j++){
                ans=min(ans,w[x]+a[x][i].second+dis[a[x][i].first][a[y][j].first]+a[y][j].second+w[y]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
