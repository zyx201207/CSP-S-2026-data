#include<bits/stdc++.h>
using namespace std;
const int maxm=500005;
const int maxn=510;
int z,n,m,d,q;
int w[maxm],f[maxn][maxn];
int a[maxm][2];
int c[maxm];
struct node{
    int u,v;
    int cst;
}g[maxn][25];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>z>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        while(k--){
            int x,t;
            scanf("%d%d",&x,&t);
            if(a[i][0]==0) a[x][0]=i;
            else{
                f[i][a[x][0]]=x;
                f[a[x][0]][i]=x;
                a[x][1]=i;

            }
            c[x]+=t;
        }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        int tot=0;
        tot+=w[x]+w[y];
        if(a[x][1]==0){
            tot+=c[x]+c[y];
            tot+=c[f[a[x][0]][a[y][0]]];
        }
        printf("%d\n",tot);
    }
    return 0;
}
