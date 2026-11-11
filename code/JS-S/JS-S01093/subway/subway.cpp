#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int edge[2000][2000],dis[2000][2000],ext[2000];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    for(int i=1;i<=1949;i++)
        for(int j=1;j<=1949;j++)dis[i][j]=0x3f3f3f;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>ext[i];
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        for(int j=1;j<=t;j++){
            int temp_pos,temp_cost;
            cin>>temp_pos>>temp_cost;
            dis[i+m][temp_pos]=dis[temp_pos][i+m]=temp_cost;
        }
    }
    for(int k=1;k<=n+m;k++)
        for(int i=1;i<=n+m;i++)
            for(int j=1;j<=n+m;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=q;i++){
        int tempx,tempy;
        cin>>tempx>>tempy;
        cout<<dis[tempx][tempy]+ext[tempx]+ext[tempy]<<endl;
    }
    return 0;
}
