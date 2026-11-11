#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long dis[1005][1005];
long long t[500005];
int a[500005];
int w[500005];
int k[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(i!=j){
                dis[i][j]=1e18;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[j]>>t[j];
        }
        for(int j=1;j<=k[i];j++){
            for(int l=1;l<=k[i];l++){
                if(j!=l){
                    dis[a[j]][a[l]]=t[j]+t[l];
                }
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<dis[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}

