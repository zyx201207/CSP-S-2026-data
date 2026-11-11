#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[1005][20005];
int x[505][505];
bool vis[505];
long long ans=1e9;
void dfs(int s,int e,int T,int now){
    if(now==e){
        x[s][e]=min(T,x[s][e]);
        x[e][s]=x[s][e];
        return ;
    }
    for(int i=1;i<=n;i++){
        if(i!=now){
            if(x[now][i]!=1e9&&!vis[i]){
                vis[i]=1;
                dfs(s,e,T+x[now][i],i);
                vis[i]=0;
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[0][i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            int x,y;
            cin>>x>>y;
            a[i][x]=y;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            x[i][j]=1e9;
            for(int k=1;k<=m;k++){
                if(a[i][k]&&a[j][k]){
                    x[i][j]=min(x[i][j],a[i][k]+a[j][k]);
                    x[j][i]=x[i][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            vis[i]=1;
            dfs(i,j,0,i);
            vis[i]=0;
        }
    }
    while(q--){
        int st,ed;
        cin>>st>>ed;
        int T=1e9;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][st]&&a[j][ed]){
                    T=min(T,x[i][j]+a[i][st]+a[0][st]+a[0][ed]+a[j][ed]);
                }
            }
        }
        cout<<T<<endl;
    }
    return 0;
}
