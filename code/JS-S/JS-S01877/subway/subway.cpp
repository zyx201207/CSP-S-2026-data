#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=1e4+5;
int C,n,m,d,q;
int w[500005],g[N][N],a[N],t[N];
void prep();
void init();
void dr();
void work();
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int T=1;
//    cin>>T;
    prep();
    while(T--){
        init();
        dr();
        work();
    }
    return 0;
}
void prep(){
}
void init(){
    memset(g,0x3f,sizeof(g));
}
void dr(){
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        for(int j=1;j<=k;j++) cin>>a[j]>>t[j];
        for(int j=1;j<=k;j++)
            for(int l=1;l<=k;l++) g[a[j]][a[l]]=t[j]+t[l];
    }
}
void work(){
    for(int k=1;k<=m;k++)
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    while(q--){
        int x,y; cin>>x>>y;
        cout<<g[x][y]+w[x]+w[y]<<'\n';
    }
}
