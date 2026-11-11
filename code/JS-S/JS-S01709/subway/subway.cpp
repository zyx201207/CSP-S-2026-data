#include<bits/stdc++.h>
using namespace std;
const int M=5e5+8,N=505,Q=1e5+5;
int c,n,m,d,q,sum,ans=INT_MAX;
int w[M],k[N],a[N][M],t[N][M],x[Q],y[Q];
bool vis[M];
void dfs(int kk,int tg){
    if(kk==tg){
        ans=min(sum,ans);
        return;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    return 0;
}
