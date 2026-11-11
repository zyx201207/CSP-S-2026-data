#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=505;
typedef long long ll;
ll f[N][N],w[N],a[N][N],t[N][N];
ll c,n,m,d,q;
void floyd(){
    for(ll k=1;k<=m;k++){
        for(ll i=1;i<=m;i++){
            for(ll j=1;j<=m;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(f,0x3f,sizeof f);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++)cin>>w[i];
    for(ll i=1;i<=n;i++){
        ll k;
        cin>>k;
        for(ll j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][a[i][j]];
        }
        for(ll j=1;j<=k;j++){
            for(ll o=1;o<=k;o++){
                f[a[i][j]][a[i][o]]=f[a[i][o]][a[i][j]]=min(f[a[i][j]][a[i][o]],t[i][a[i][j]]+t[i][a[i][o]]);
            }
        }
    }
    floyd();
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cout<<f[i][j]<<" ";
        }cout<<'\n';
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        cout<<w[l]+w[r]+f[l][r]<<'\n';
    }
    return 0;
}
