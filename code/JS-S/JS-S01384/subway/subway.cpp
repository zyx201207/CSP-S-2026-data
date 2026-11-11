#include<bits/stdc++.h>
using  namespace std;
#define ll long long
ll w[500005];
struct node{
    ll a,t;
}e[505][505];
vector<node>g[505];
ll c,n,m,d,q;
ll k[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++){
        cin>>w[i];
    }
    for(ll i=1;i<=n;i++){
        cin>>k[i];
        for(ll j=1;j<=k[i];j++){
            cin>>e[i][j].a>>e[i][j].t;
        }
    }

    while(q--){
        ll x,y;
        cin>>x>>y;
        ll K,A,K2,A2;
        bool f1=0,f2=0;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=k[i];j++){
                if(e[i][j].a==x&&f1==0){
                    K=i,A=j;
                    f1=1;
                }
                if(e[i][j].a==y&&f2==0){
                    K2=i,A2=j;
                    f2=1;
                }
            }
        }
        ll ans=w[A]+w[A2];
        for(ll j=A;j<=k[K];j++){
            ans+=e[K][j].t;
            if(j==A2){
                cout<<ans<<endl;
                break;
            }
        }
    }
    return 0;
}
