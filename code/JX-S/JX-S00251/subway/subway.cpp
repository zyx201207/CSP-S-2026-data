#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5;
int ans=0;
int c,n,m,d,q;
int t[N][N],a[N][N];
int w[N],x[N];
int l[N][N];
bool is[N][N];
int k[N];
int fa[N],fa2[N];
// vector<int> g[N];
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
            if(fa[a[i][j]]==0) fa[a[i][j]]=i;
            else{
                fa2[a[i][j]]=i;
            }
        }
        for(int j=1;j<k[i];j++){
            is[a[i][j]][a[i][j+1]]=1;
        }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        // printf("I must be lost in this game\n");
        int fx=fa[x],fy=fa[y];
        if(fx==fy){
            ans+=w[x]+w[y]+t[fx][x]+t[fx][y];
        }
        else{
            for(int i=x;i<=y;i++){
                if(fa[i]!=0 && fa2[i]!=0){
                    ans+=w[x]+t[fx][x]+t[fx][i]+t[fy][i]+t[fy][y]+w[y];
                    break;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}