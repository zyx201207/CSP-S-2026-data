#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=5e3+5;

int x[maxn],dis[maxn][maxn],ans[maxn][maxn];
vector<int> g[maxn];

int labs(int x){
    if(x<0)return -x;
    return x;
}

void dijkstra(int s){
    dis[s][s]=0;
    ans[s][s]=1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(dis[s][v]>=dis[s][u]+1){
                if(dis[s][v]>dis[s][u]+1){
                    dis[s][v]=dis[s][u]+1;
                    ans[s][v]=ans[s][u];
                    q.push(v);
                }else{
                    ans[s][v]+=ans[s][u];
                }
            }
        }
    }
}

void solve(){
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        g[i].clear();
    }

    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int nowd=labs(x[i]-x[j]);
            if(nowd>d)continue;
            g[i].push_back(j);
        }
    }

    memset(dis,0x3f,sizeof(dis));
    memset(ans,0,sizeof(ans));

    for(int i=1;i<=n;i++)
        dijkstra(i);

    int res=0;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(ans[i][j]==2)res++;
    cout<<res<<'\n';
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin>>c>>t;
    while(t--)solve();
    return 0;
}
