#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[505],a[500005],t[500005];
long long g[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(g,0x3f,sizeof(g));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    while(n--){
        int k;
        cin>>k;
        for(int i=1;i<=k;i++) cin>>a[i]>>t[i];
        for(int i=1;i<=k;i++) for(int j=i+1;j<=k;j++) g[a[i]][a[j]]=min(g[a[i]][a[j]],(long long)t[i]+t[j]);
    }
    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=m;j++) cout<<g[i][j]<<' ';
    //     cout<<'\n';
    // }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=m;j++) cout<<g[i][j]<<' ';
    //     cout<<'\n';
    // }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<min(g[x][y],g[y][x])+w[x]+w[y]<<'\n';
    }
    return 0;
}