#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[505],a[505][505],t[505][505];
bool kk[500005];
int dfs(int x,int y,int time){
    if(x==y){
        return time;
    }
    else{
        int ttime=INT_MAX;
        kk[x]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==x){
                    for(int p=1;p<=k[i];p++){
                        if(kk[a[i][p]]==0){
                            ttime=min(dfs(a[i][p],y,time+t[i][j]+t[i][p]),ttime);
                        }
                    }
                    break;
                }
            }
        }
        return ttime;   
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        memset(kk,0,sizeof(kk));
        int x,y;
        cin>>x>>y;
        cout<<dfs(x,y,0)+w[x]+w[y]<<"\n";
    }
    return 0;
}
