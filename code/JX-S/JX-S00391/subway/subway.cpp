#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[510],w[500010],a[510],t[510],f[500010],f2[500010];
int dw[500010];
int dw2[500010];
int hcd[510][510];
bool hc[500010]={false};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    int x,y;
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=2*k[i];j++){
            scanf("%d%d",&x,&y);
            if(f[x]){
                f2[x]=i;
                hcd[f[x]][i]=x;
                hc[x]=1;
                dw2[x]=y;

            }
            else{
                f[x]=i;
                dw[x]=y;
            }
        }
    }
    int ans=0;
    while(q--){
        scanf("%d%d",&x,&y);
        if(!hc[x]&&!hc[y]){
            if(f[x]==f[y]){
                ans+=dw[x];
                ans+=dw[y];
            }
            else{
                int X=f[x],Y=f[y];
                if(X>Y){
                    swap(X,Y);
                }
                ans+=dw[hcd[X][Y]];
                ans+=dw2[hcd[X][Y]];
                ans+=dw[x];
                ans+=dw[y];
            }
        }
        else{
            if(f[x]==f2[y]){
                ans+=dw[x];
                ans+=dw2[y];
            }
            else if(f2[x]==f[y]){
                ans+=dw2[x];
                ans+=dw[y];
            }
            else{
                int X=f[x],Y=f[y];
                if(X>Y){
                    swap(X,Y);
                }
                ans+=dw[hcd[X][Y]];
                ans+=dw2[hcd[X][Y]];
                ans+=dw[x];
                ans+=dw[y];
            }
        }
        ans+=w[x];
        ans+=w[y];
        printf("%d\n",ans);
    }
    return 0;
}
