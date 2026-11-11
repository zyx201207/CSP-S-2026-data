#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5,D=23;
const long long inf=1e18+1;
int c,n,m,d,q,w[M];
int id[M][D],t[M][D];
long long dis[N][N],ans;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        int k;scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int x,y;scanf("%d%d",&x,&y);
            id[x][0]++;id[x][id[x][0]]=i,t[x][id[x][0]]=y;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=inf;
        }dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int x=1;x<=id[i][0];x++){
            for(int y=x+1;y<=id[i][0];y++){
                int a=id[i][x],b=id[i][y];
                long long temp=t[i][x]+t[i][y];
                dis[a][b]=temp,dis[b][a]=temp;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                long long temp=dis[i][k]+dis[k][j];
                if(dis[i][j]>temp) dis[i][j]=temp;
            }
        }
    }
    while(q--){
        int l,r;scanf("%d%d",&l,&r);ans=inf;
        for(int i=1;i<=id[l][0];i++){
            for(int j=1;j<=id[r][0];j++){
                int a=id[l][i],b=id[r][j];
                long long temp=dis[a][b];
                temp+=w[l]+w[r];temp+=t[l][i]+t[r][j];
                if(temp<ans) ans=temp;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}