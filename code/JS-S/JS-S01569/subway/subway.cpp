#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,M=505;
struct er{
    ll to,w;
};
vector<er> vec[N+M];
ll a[N];
ll ma[M][M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll c,n,m,d,q;
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            ma[i][j]=-1;
            if(i==j)ma[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            ll to,w;
            cin>>to>>w;
            vec[n+i].push_back({to,w});
            vec[to].push_back({n+i,w});
        }
    }
    for(int i=1;i<=n;i++){
        for(auto u:vec[i]){
            for(auto v:vec[i]){
                ll uto=u.to-n,vto=v.to-n,uw=u.w,vw=v.w;
                if(ma[uto][vto]>=0)ma[uto][vto]=ma[vto][uto]=min(ma[uto][vto],uw+vw);
                else ma[uto][vto]=ma[vto][uto]=uw+vw;
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            if(ma[i][k]<0)continue;
            for(int j=1;j<=m;j++){
                if(ma[k][j]<0)continue;
                if(ma[i][j]>=0)ma[i][j]=min(ma[i][j],ma[i][k]+ma[k][j]);
                else ma[i][j]=ma[i][k]+ma[k][j];
            }
        }
    }
    while(q--){
        int ux,vx;
        cin>>ux>>vx;
        ll ans=1e18;
        for(auto u:vec[ux]){
            for(auto v:vec[vx]){
                ans=min(ans,u.w+v.w+ma[u.to-n][v.to-n]);
            }
        }
        cout<<ans+a[ux]+a[vx]<<'\n';
    }
    return 0;
}
