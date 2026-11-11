#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int c,n,m,d,p,k[510],ans;
int dist[N][N],w1[N],t[510][N],s[510][N],vis[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&p);
    for(int i=1;i<=m;i++)
        scanf("%d",&w1[i]);
        for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++)
            dist[i][j]=1e9;
        }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%d%d",&t[i][j],&s[i][j]);
            for(int p=1;p<j;p++)
                dist[t[i][p]][t[i][j]]=min(dist[t[i][p]][t[i][j]],s[i][p]+s[i][j]);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m&&i!=j;k++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i=1;i<=p;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        ans=w1[l]+w1[r];
        ans+=dist[l][r];
        printf("%d\n",ans);
    }
    return 0;
}
