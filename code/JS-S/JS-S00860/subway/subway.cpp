#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int n,m;//n :point number   ,m:edge number
long long dis[1507][1507];
vector<pii>g[501007];
int k[501007];
void dijkstra(int s){
    priority_queue<pii>q;
    dis[s][s]=0;
    q.push(make_pair(0,s));
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
          }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,nn,mm,d,qq;
    cin>>c>>nn>>mm>>d>>qq;
    int outtime[501007];
    for(int i=1;i<=mm;i++){
        cin>>outtime[i];
    }
    for(int i=1;i<=nn;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int nowst,tneed;
            cin>>nowst>>tneed;
            g[nowst].push_back(make_pair(tneed,i+mm));
            g[i+mm].push_back(make_pair(tneed,nowst));
        }
    }
    for(int i=1;i<=(nn+mm);i++) dijkstra(i);
    for(int i=1;i<=qq;i++){
        int x,y;
        cin>>x>>y;
        if(x==y){
            cout<<0<<'\n';
            exit(0);
        }
        cout<<(dis[x][y]+outtime[x]+outtime[y])<<'\n';
    }
    return 0;
    //for(int i=1;i<=n;i++) cout<<dis[i]<<' ';
    //cout<<'\n';
}
