#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,qq,w[500005],k[505],used[500005][3],dis[500005][3];
vector<int> q[500005][2],s[500005][2];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > r;
void dijkstra(int x,int y){
    while(!r.empty()){
        int u=r.top().second;
        r.pop();
        if(u>0){
            if(used[u][1]!=0) continue;
            used[u][1]=1;
            for(int i=0;i<q[u][0].size();i++){
                int v=q[u][0][i],z=q[u][1][i];
                if(dis[u][1]+z<dis[v][2]){
                    dis[v][2]=dis[u][1]+z;
                    r.push(make_pair(dis[v][2],-v));
                }
            }
        }
        else{
            u=-u;
            if(used[u][2]!=0) continue;
            used[u][2]=1;
            for(int i=0;i<s[u][0].size();i++){
                int v=s[u][0][i],z=s[u][1][i];
                if(dis[u][2]+z<dis[v][1]){
                    dis[v][1]=dis[u][2]+z;
                    r.push(make_pair(dis[v][1],v));
                }
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>qq;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int a,t;
            cin>>a>>t;
            q[a][0].push_back(i);
            q[a][1].push_back(t);
            s[i][0].push_back(a);
            s[i][1].push_back(t);
        }
    }
    while(qq--){
        int x,y;
        cin>>x>>y;
        for(int i=1;i<=m;i++){
            dis[i][1]=2e9; used[i][1]=0;
        }
        for(int i=1;i<=n;i++){
            dis[i][2]=2e9; used[i][2]=0;
        }
        dis[x][1]=0;
        r.push(make_pair(dis[x][1],x));
        dijkstra(x,y);
        cout<<dis[y][1]+w[x]+w[y]<<endl;
    }
    return 0;
}
