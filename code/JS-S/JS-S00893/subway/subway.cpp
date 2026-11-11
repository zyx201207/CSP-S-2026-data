#include <bits/stdc++.h>
#define pii pair <long long,pair <int,int> >
using namespace std;
typedef long long ll;
int c,n,m,d,Q,w[500005],k[505];
ll T[505][1005];
bool vis[1005][505];
vector <pair <int,int> > a[505],b[500005];
void bfs(int s,int t){
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=500;j++) vis[i][j]=0;
    }
    priority_queue <pii,vector <pii >,greater <pii > > q;
    while(!q.empty()) q.pop();
    for(auto x:b[s]) q.push({w[s]+w[t]+x.second,{s,x.first}});
    while(!q.empty()){
        ll tm=q.top().first;
        int st=q.top().second.first,sb=q.top().second.second;
        q.pop();
        if(st==t){
            long long ad=0;
           for(auto v:b[st]){
                if(v.first==sb){
                    ad=v.second;
                    break;
                }
            }
            cout<<tm+T[sb][st]<<'\n';
            return;
        }
        if(vis[st][sb]) continue;
        vis[st][sb]=1;
        for(auto v:a[sb]){
            if(v.first!=st) q.push({tm,{v.first,sb}});
        }
        for(auto v:b[st]){
            if(v.first!=sb) q.push({tm+v.second+T[sb][st],{st,v.first}});
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1,x,y;j<=k[i];j++){
            cin>>x>>y;
            a[i].push_back({x,y});
            b[x].push_back({i,y});
            T[i][x]=y;
        }
    }
    while(Q--){
        int x,y;
        cin>>x>>y;
        bfs(x,y);
    }
    return 0;
}
