#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=1e4+5;
long long c,n,m,d,p,minn=999999999;
bool zhan[M],xian[M];
int w[M],t[M],k[M];
int a[M][M],b[M][M];//a:zhan->xian  b:xian->zhan

void dfs(int x,int y,int step){
    //cout<<x<<" ";
    if(x==y){
        if(step<minn)minn=step;
        //cout<<'\n';
        return;
    }
    else{
        for(int i=1;i<=n;i++){// nen qu na tiao xian
            if(!xian[i]&&a[x][i]>0){
                xian[i]=1;
                for(int j=1;j<=m;j++){//nen qu na ge zhan
                    if(!zhan[j]&&b[i][j]>0){
                        zhan[j]=1;
                        dfs(j,y,step+a[x][i]+b[i][j]);
                        zhan[j]=0;
                    }
                }
                xian[i]=0;
            }
        }
    }
    return;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>p;

    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int o,t;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>o>>t;
            a[o][i]=t;
            b[i][o]=t;
        }
    }
    while(p--){
        int x,y;
        cin>>x>>y;

        minn=999999999;
        for(int i=1;i<=m;i++){
            zhan[i]=0;
        }
        for(int i=1;i<=n;i++){
            xian[i]=0;
        }
        zhan[x]=1;dfs(x,y,w[x]+w[y]);
        cout<<minn<<'\n';
    }

    return 0;
}

