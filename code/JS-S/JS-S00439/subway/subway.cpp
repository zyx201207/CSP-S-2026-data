#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e2+10,M=5e5+10,INF=1e18;
ll w[N],a[M],t[M],f[N][N];
ll c,n,m,d,q,k,x,y;
void solve1(){
    for(ll i=1;i<=m;i++) cin>>w[i];
    memset(f,63,sizeof(f));
    for(ll br=1;br<=n;br++){
        cin>>k;
        for(ll i=1;i<=k;i++) cin>>a[i]>>t[i];
        for(ll i=1;i<=k;i++){
            for(ll j=i+1;j<=k;j++){
                f[a[i]][a[j]]=min(f[a[i]][a[j]],t[i]+t[j]);
                f[a[j]][a[i]]=min(f[a[j]][a[i]],t[i]+t[j]);
            }
        }
    }
    for(ll z=1;z<=m;z++){
        for(ll i=1;i<=m;i++){
            for(ll j=1;j<=m;j++){
                f[i][j]=min(f[i][j],f[i][z]+f[z][j]);
            }
        }
    }
    for(ll i=1;i<=q;i++){
        cin>>x>>y;
        cout<<f[x][y]+w[x]+w[y]<<'\n';
    }
}
void solve2(){
    for(ll i=1;i<=m;i++) cin>>w[i];
    for(ll br=1;br<=n;br++){
        cin>>k;
        for(ll i=1;i<=k;i++) cin>>a[i]>>t[i];
        for(ll i=1;i<=k;i++){
            for(ll j=i+1;j<=k;j++){
                f[a[i]][a[j]]=min(f[a[i]][a[j]],t[i]+t[j]);
                f[a[j]][a[i]]=min(f[a[j]][a[i]],t[i]+t[j]);
            }
        }
    }
    for(ll z=1;z<=m;z++){
        for(ll i=1;i<=m;i++){
            for(ll j=1;j<=m;j++){
                f[i][j]=min(f[i][j],f[i][z]+f[z][j]);
            }
        }
    }
    for(ll i=1;i<=q;i++){
        cin>>x>>y;
        cout<<f[x][y]+w[x]+w[y]<<'\n';
    }
}
ll cnt[M],v[M][2],minn=INF,ans=INF;
void solve3(){
    for(ll i=1;i<=m;i++) cin>>w[i];
    for(ll i=1;i<=n;i++){
        cin>>k;
        for(ll j=1;j<=k;j++){
            cin>>a[j]>>t[j];
            cnt[a[j]]++;
            v[a[j]][i]=t[j];
        }
    }
    for(ll i=1;i<=m;i++){
        if(cnt[i]==2) minn=min(minn,v[i][1]+v[i][2]);
    }
    for(ll i=1;i<=q;i++){
        cin>>x>>y;
        if(v[x][1]&&v[y][1]) ans=min(ans,v[x][1]+v[y][1]);
        if(v[x][2]&&v[y][2]) ans=min(ans,v[x][2]+v[y][2]);
        if(v[x][1]&&v[y][2]) ans=min(ans,v[x][1]+v[y][2]+minn);
        if(v[x][2]&&v[y][1]) ans=min(ans,v[x][2]+v[y][1]+minn);
        cout<<ans+w[x]+w[y]<<'\n';
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    if(c<=11) solve1();
    else if(c>=12&&c<=19) solve1();
    else if(c>=20&&c<=21) solve3();
    return 0;
}
