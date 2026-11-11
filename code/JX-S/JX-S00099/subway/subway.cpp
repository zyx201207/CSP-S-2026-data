#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
int g[20005][20005];
int c,n,m,d,q;
int w[20005];//a[20005],t[20005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)cin>>w[i];
    for(int i=0;i<=m*m*2+1;++i){
        for(int j=0;j<=m*m*2+1;++j){
                g[i][j]=INF;
                if(i==j)g[i][j]=0;
        }
    }
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        int pre=0;
        for(int j=1;j<=k;++j){
            int a,t;
            cin>>a>>t;
            if(j==1)g[a][a*m*2+1]=t,g[a*m*2+1][a]=t;
            else if(j==k)g[a][a*m+1]=t,g[a*m+1][a]=t;
            else{
                g[a][a*m+1]=t,g[a*m+1][a]=t;
                g[a][a*m*2+1]=t,g[a*m*2+1][a]=t;
            }
            if(pre!=0){
                g[a*m+1][pre*m*2+1]=0;
                g[pre*m*2+1][a*m+1]=0;
            }
            pre=a;
        }
    }
    for(int k=1;k<=m*m*2+1;++k){
        for(int i=1;i<=m*m*2+1;++i){
            for(int j=1;j<=m*m*2+1;++j){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    for(int i=1;i<=q;++i){
        int x,y;
        cin>>x>>y;
        cout<<g[x][y]+w[x]+w[y]<<"\n";
    }
    return 0;
}
