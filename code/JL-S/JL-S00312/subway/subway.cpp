#include<bits/stdc++.h>
using namespace std;
struct node{
    int a1,t1;
}a[10][15];
int a2[20];
short tu[20][20][20];
int k[20];
int mi=INT_MAX;
int zouguo[20];
short xian[20][20];
short xian2[20];
int c,n,m,d,q;
void dfs(int x,int y,int ti,int xian3){
    if(x==y){
        mi=min(mi,ti);
        return ;
    }
    zouguo[xian3]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            for(int k=1;k<=n;k++){
                if(zouguo[k]==1) continue;
                if(xian2[a[i][j].a1]>1){
                    for(int l=1;l<=n;l++){
                        if(zouguo[l]) continue;
                        if(xian[l][a[i][j].a1]==1){
                            zouguo[l]=1;
                            dfs(j,y,ti+a[i][j].t1+a[l][j].t1,l);
                            zouguo[l]=0;
                        }
                    }
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a2[i];
    }
    for(int i=1;i<=n;i++){
            cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j].a1>>a[i][j].t1;
            xian[i][a[i][j].a1]=1;
            xian2[a[i][j].a1]++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            for(int k1=j+1;k1<=k[i];k1++){
                tu[i][a[i][j].a1][a[i][k1].a1]=1;
                tu[i][a[i][k1].a1][a[i][j].a1]=1;
            }
        }
    }
    while(q--){
        int x1,y1;
        cin>>x1>>y1;
        int xian4,shi,shi2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j].a1==x1){
                    xian4=i;
                    shi=a[i][j].t1;
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j].a1==y1){
                    shi2=a[i][j].t1;
                    break;
                }
            }
        }
        if(tu[xian4][x1][y1]==1) cout<<a2[x1]+a2[y1]<<'\n';
        else{
            dfs(x1,y1,shi+shi2,xian4);
            cout<<mi+a2[x1]+a2[y1]<<'\n';
        }
    }
    return 0;
}
