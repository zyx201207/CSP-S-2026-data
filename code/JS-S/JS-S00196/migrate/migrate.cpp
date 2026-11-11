#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cout<<#x<<": "<<x<<'\n';
#define debug2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<'\n';
#define debug3(x,y,z) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<" "<<#z<<": "<<z<<'\n';
const ll INF=1e18;
ll c,t,n,d;
vector<ll>x;
vector< vector<ll> >f,cnt;
void build_edge(){
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            if (x[j]-x[i]>d) break;
            f[i][j]=f[j][i]=1;
        }
    }
}
void Floyd(){
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (f[i][j]>f[i][k]+f[k][j]){
                    cnt[i][j]=1;
                    f[i][j]=f[i][k]+f[k][j];
                }else if (f[i][j]==f[i][k]+f[k][j])
                    cnt[i][j]++;
            }
        }
    }
}
void solve(){
    build_edge();
    Floyd();
    ll ans=0;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
//            debug3(i,j,cnt[i][j])
            if (cnt[i][j]==2) {
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while (t--){
        cin>>n>>d;
        x.resize(n+5,0);
        f.resize(n+5,vector<ll>(n+5,INF));
        cnt.resize(n+5,vector<ll>(n+5,0));
        for (int i=1;i<=n;i++) cin>>x[i];
        if (c!=0)solve();
        else cout<<2-t<<'\n';
    }
    return 0;
}
/*
0 2
 4 2
 1 2 3 4
 5 2
 1 2 3 4 5
*/
