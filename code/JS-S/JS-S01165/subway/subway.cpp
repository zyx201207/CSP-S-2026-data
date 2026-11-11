#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=510;
int c,n,m,d,q;
int w[N],a[N][N],t[N][N],f[N][N];
int main(){
    freopen("subway","r",stdin);
    freopen("subway","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    memset(f,0x3f,sizeof f);
    for(int l=1;l<=n;l++){
        int k;
        cin>>k;
        for(int i=1;i<=k;i++){
            cin>>a[l][i]>>t[l][i];

        }
        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++){
                f[a[l][i]][a[l][j]]=(t[l][i]+t[l][j]);
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        int s,t;
        cin>>s>>t;
        cout<<f[s][t]+w[s]+w[t]<<"\n";
    }
    return 0;
}

