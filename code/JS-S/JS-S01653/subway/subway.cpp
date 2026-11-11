#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q,k,x,y,t1,t2;
long long dis,w[M],f[N][N],ans[N][N];
vector<pair<int,long long>> v[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%d%lld",&x,&dis);
            v[x].push_back({i,dis});
        }
        for(int j=1;j<=n;j++){
            if(i!=j) f[i][j]=1e18;
        }
    }
    for(int i=1;i<=m;i++){
        k=v[i].size();
        for(int j=0;j<k;j++){
            for(int p=j+1;p<k;p++){
                x=v[i][j].first;
                y=v[i][p].first;
                f[x][y]=min(f[x][y],v[i][j].second+v[i][p].second);
                f[y][x]=f[x][y];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans[i][j]=f[i][j];
            ans[j][i]=f[i][j];
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(ans[i][k]!=1e18&&ans[k][j]!=1e18){
                    ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
                }
            }
        }
    }
    while(q--){
        scanf("%d%d",&x,&y);
        int k1=v[x].size(),k2=v[y].size();
        dis=-1;
        for(int i=0;i<k1;i++){
            for(int j=0;j<k2;j++){
                t1=v[x][i].first;
                t2=v[y][j].first;
                if(dis==-1) dis=ans[t1][t2]+v[x][i].second+v[y][j].second;
                else dis=min(dis,ans[t1][t2]+v[x][i].second+v[y][j].second);
            }
        }
        printf("%lld\n",dis+w[x]+w[y]);
    }
    return 0;
}
