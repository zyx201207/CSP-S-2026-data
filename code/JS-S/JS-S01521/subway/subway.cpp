#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=505,M=5e5+5,Max=5e14+5;
ll c,n,m,d,q;
ll a[N][N],w[M];
vector<pair<ll,ll> > v[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            a[i][j]=Max;
        }
        a[i][i]=0;
    }
    for(ll i=1;i<=m;i++){
        cin>>w[i];
    }
    for(ll i=1;i<=n;i++){
        ll num;
        cin>>num;
        for(ll j=1;j<=num;j++){
            ll x,y;
            cin>>x>>y;
            for(auto k:v[x]){
                a[i][k.first]=min(a[i][k.first],k.second+y);
                a[k.first][i]=a[i][k.first];
            }
            v[x].push_back({i,y});
        }
    }
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            if(i==k)continue;
            for(ll j=i;j<=n;j++){
                if(j==k||j==i){
                    continue;
                }
                if(a[i][k]!=Max&&a[k][j]!=Max&&a[i][k]+a[k][j]<a[i][j]){
                    a[i][j]=a[i][k]+a[k][j];
                    a[j][i]=a[i][j];
                }
            }
        }
    }
/*    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/
    while(q--){
        ll x,y;
        cin>>x>>y;
        ll ans=LONG_LONG_MAX;
        for(auto i:v[x]){
            for(auto j:v[y]){
                ans=min(ans,i.second+j.second+a[i.first][j.first]);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
