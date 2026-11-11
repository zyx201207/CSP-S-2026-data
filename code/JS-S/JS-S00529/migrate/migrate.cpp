#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=310;

int dis[N][N][N],d,n,a[N];

void bfs(int x){
    queue<pii> q;
    q.push({x,0});
    while(q.size()){
        pii t=q.front(); q.pop();
        int u=t.first,s=t.second;
        dis[x][u][s]++;
        for(int i=u+1;i<=n;i++){
            if(a[i]-a[u]<=d){
                q.push({i,s+1});
            }
        }
    }
}



signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T; cin>>c>>T;
    while(T--){
        memset(dis,0,sizeof dis);
        cin>>n>>d;
        for(int i=1;i<=n;i++) scanf("%lld",a+i);
        int ans=0;
        for(int i=1;i<=n;i++) bfs(i);
        for(int i=1;i<=n;i++)   
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++){
                    if(dis[i][j][k]){
                        if(dis[i][j][k]==2) ans++;
                        break;
                    }
                }
        cout<<ans<<endl;
        // for(int i=1;i<=n;i++)   
        //     for(int j=1;j<=n;j++)
        //         for(int k=1;k<=n;k++){
        //             cout<<"dis["<<i<<"]["<<j<<"]["<<k<<"]="<<dis[i][j][k]<<endl;
        //         }
    }
    return 0;
}