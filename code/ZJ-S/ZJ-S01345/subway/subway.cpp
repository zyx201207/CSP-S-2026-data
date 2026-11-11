#include<bits/stdc++.h>
using namespace std;
int w[20001],k[20001],a[20001][20001],t[20001][20001],g[20001][20001],h[20001][20001],xian1[20001],xian2[20001];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            h[a[i][j]][i]=t[i][j];
        }
    }
    for(int j=1;j<=n;j++){
        for(int x=1;x<=n;x++){
            if(j!=x){
                g[j][x]=1e9;
            }
        }
    }   
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int x=1;x<=n;x++){
                if(h[i][j]>0&&h[i][x]>0&&j!=x){
                    g[j][x]=min(g[j][x],h[i][j]+h[i][x]);
                    g[x][j]=g[j][x];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int x=1;x<=n;x++){
                if(i!=j&&i!=x&&j!=x){
                    g[i][j]=min(g[i][j],g[i][x]+g[x][j]);
                    g[j][i]=g[i][j];
                }
            }
        }
    }
    int x,y;
    for(int e=1;e<=q;e++){
        int ans=1e9;
        int j1=0;
        int j2=0;
        cin>>x>>y;
        for(int i=1;i<=n;i++){
            bool flag1=0;
            bool flag2=0;
            for(int j=1;j<=k[i];j++){
                if(flag1!=1){
                    if(x==a[i][j]){
                        xian1[j1]=i;
                        j1++;
                        flag1=1;
                    }
                }
                if(flag2!=1){
                    if(y==a[i][j]){
                        xian2[j2]=i;
                        j2++;
                        flag2=1;
                    }                    
                }
            }
        }
        int j3,j4;
        for(int i=1;i<=j1;i++){
            for(int j=1;j<=j2;j++){
                ans=min(ans,g[xian1[i]][xian2[j]]);
                j3=xian1[i];
                j4=xian2[j];
            }
        }
        ans+=w[x]+w[y]+h[x][j3]+h[y][j4];
        cout<<ans<<endl;
    }
    return 0;
}