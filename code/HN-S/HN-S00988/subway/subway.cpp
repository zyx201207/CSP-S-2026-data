#include <bits/stdc++.h>
#define lint __int128
#define int long long
#define Il inline
#define fi first
#define se second
#define vec vector
#define pb push_back
#define IT ::iterator
#define p_q priority_queue

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef double db;
const int N=5e5,M=500,Inf=1e18;
const db eps=1e-9;

// bool P1;

Il void chkmin(int &x,int y){
    x=min(x,y);
    return;
}

int testcase,n,m,K,Q,a[N+5],d[M+5][M+5];
vec<pii>v[N+5];

// bool P2;

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // cout<<abs((&P1)-(&P2))/1024/1024;return 0;
    cin>>testcase>>n>>m>>K>>Q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1,tn;i<=n;i++){
        cin>>tn;
        for(int j=1,x,y;j<=tn;j++){
            cin>>x>>y,v[x].pb({i,y});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[i][j]=(i^j?Inf:0ll);
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=0;i<(int)v[k].size();i++){
            for(int j=i+1;j<(int)v[k].size();j++){
                pii px=v[k][i],py=v[k][j];
                chkmin(d[px.fi][py.fi],px.se+py.se);
                chkmin(d[py.fi][px.fi],px.se+py.se);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<d[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    while(Q--){
        int x,y,ans=Inf;cin>>x>>y;
        for(pii i:v[x]){
            for(pii j:v[y]){
                ans=min(ans,i.se+j.se+d[i.fi][j.fi]);
            }
        }
        // cout<<a[x]<<' '<<a[y]<<' ';
        cout<<a[x]+a[y]+ans<<'\n';
    }
    return 0;
}
/*
*/