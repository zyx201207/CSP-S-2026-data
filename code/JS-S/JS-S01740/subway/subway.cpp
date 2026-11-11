#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q;
int w[M],k[M],a[N][M],t[N][M];
int DFS(int x,int y,int kx,int ky){
    if(x==y)return t[kx][ky]+w[y];
    int mn=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            if(a[i][j]==x){
                if(i==kx&&j+1<=k[i]){
                    mn=min(mn,DFS(a[i][j+1],y,i,j+1));
                }
                if(i!=kx&&j+1<=k[i]){
                    mn=min(mn,t[kx][ky]+t[i][j]+DFS(a[i][j+1],y,i,j+1));
                }
            }
        }
    }
    return mn;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%d%d",&a[i][j],&t[i][j]);
        }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        int mn=INT_MAX;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==x){
                    if(j+1<=k[i])mn=min(mn,w[x]+t[i][j]+DFS(a[i][j+1],y,i,j+1));
                }
            }
        }
        printf("%d",mn);
    }
    return 0;
}
