#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;

int c,n,m,d,q,to,ti,x,y,xi,yi,xj,yj;
int w[N],a[N][10],t[N][10];
bool vis[N],flagy,flagx;
ll ans;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=2*k;j++){
            scanf("%d%d",&to,&ti);
            a[j][k]=to;
            t[j][k]=ti;
        }
    }
    while(q--){
        ans=0;
        scanf("%d%d",&x,&y);
        ans+=w[x]+w[y];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=2;j++){
                if(a[i][j]==y){
                    yi=i;
                    yj=j;
                }
                if(a[i][j]==x){
                    xi=i;
                    xj=j;
                }
            }
        }
        if(yi<=xi){
            for(int i=yi;i>=xi;i--){
                for(int j=1;j<=2;j++){
                    if(yi==2&&j==1&&!flagy){
                        flagy=true;
                        continue;
                    }
                    if(xi==2&&j==1&&!flagx){
                        flagx=true;
                        continue;
                    }
                    ans+=t[i][j];
                }
            }
        }
        else{
            for(int i=yi;i<=xi;i++){
                for(int j=1;j<=2;j++){
                    if(yi==2&&j==1&&!flagy){
                        flagy=true;
                        continue;
                    }
                    if(xi==2&&j==1&&!flagx){
                        flagx=true;
                        continue;
                    }
                    ans+=t[i][j];
                }
            }
        }
        cout<<ans<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
