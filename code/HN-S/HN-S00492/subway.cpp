#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,d;
int w[500005];
long long dis[505][505];
vector<pair<int,int>> to[500005];
void Work(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int id,dis;
            cin>>id>>dis;
            to[id].push_back({i,dis});
        }
    }
    for(int i=1;i<=m;i++){
        for(pair<int,int> &j:to[i]){
            for(pair<int,int> &k:to[i]){
                dis[j.first][k.first]=min(dis[j.first][k.first],1ll*j.second+k.second);
                dis[k.first][j.first]=min(dis[k.first][j.first],1ll*j.second+k.second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(i==k) continue;
            for(int j=1;j<=n;j++){
                if(j==i||j==k) continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         printf("dis[%d][%d]=%lld\n",i,j,dis[i][j]);
    //     }
    // }
    for(int i=1;i<=q;i++){
        int a,b;
        cin>>a>>b;
        long long ans=1e18;
        for(pair<int,int> &j:to[a]){
            for(pair<int,int> &k:to[b]){
                // printf("Debug:%d(%d)->%d(%d)=%lld+%d+%d+%d+%d\n",a,j.first,b,k.first,dis[j.first][k.first],j.second,k.second,w[a],w[b]);
                ans=min(ans,dis[j.first][k.first]+j.second+k.second+w[a]+w[b]);
            }
        }
        cout<<ans<<'\n';
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Work();
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/