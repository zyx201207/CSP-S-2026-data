#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005];
long long k[505];
long long a[505][50005];
long long t[505][50005];
long long l[505][505];
long long dis[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
           cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=INT_MAX;
            if(i==j){
                dis[i][i]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int x=1;x<=k[i];x++){
                for(int y=1;y<=k[j];y++){
                    if(a[i][x]==a[j][y]){
                        dis[i][j]=min(dis[i][j],t[i][x]+t[j][y]);
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            l[i][j]=INT_MAX;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                l[i][j]=min(l[i][j],dis[i][j]);
                l[i][j]=min(l[i][j],dis[i][k]+dis[j][k]);
            }
        }
    }

    for(int i=1;i<=q;i++){
        long long x,y;
        cin>>x>>y;
        long long x1,y1,x2,y2;
        long long ans=0;
        ans+=w[x];
        ans+=w[y];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==x){
                    x1=i;
                    x2=j;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==y){
                    y1=i;
                    y2=j;
                    if(x1==y1){
                        break;
                    }
                }
            }
            if(x1==y1){
                break;
            }
        }
        ans+=t[x1][x2];
        ans+=t[y1][y2];
        cout<<ans+l[x1][y1]<<endl;
    }
    return 0;
}
