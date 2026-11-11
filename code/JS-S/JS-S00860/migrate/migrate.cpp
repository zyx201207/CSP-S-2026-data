#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
long long dis[5007][5007];
vector<pii>g[100007];
priority_queue<pii>q;
int cnt[5007][5007];
void dijkstra(int s){
    dis[s][s]=0;
    q.push(make_pair(0,s));
    cnt[s][s]=1;
    while(!q.empty()){
          pii tmp=q.top();
          q.pop();
          int now=tmp.second;
          for(int i=0;i<g[now].size();i++){
              int to=g[now][i].second;
              int w=g[now][i].first;
              if(dis[s][to]>dis[s][now]+w){
                 dis[s][to]=dis[s][now]+w;
                 q.push(make_pair(dis[s][to],to));
              }
              if(dis[s][to]==dis[s][now]+w){
                 cnt[s][to]+=cnt[s][now];
              }
          }
    }
}
void solve(){
    memset(dis,0x3f,sizeof(dis));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,a[5007];
    cin>>n>>k;
        for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1){
            int w=a[i]-a[i-1];
            g[i].push_back(make_pair(w,i-1));
            g[i-1].push_back(make_pair(w,i));
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            int w=(a[i]-a[j]);
            if(w<=k){
                g[i].push_back(make_pair(w,j));
                g[j].push_back(make_pair(w,i));
            }
        }
    }
    for(int i=1;i<=n;i++) dijkstra(i);
    int allans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(cnt[i][j]==2) allans++;
        }
    }
    cout<<allans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--) solve();
    return 0;
}
