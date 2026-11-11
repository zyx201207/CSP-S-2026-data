#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int> > a[10005];
int v[10005],dis[10005];
int w[10005],k[10005];
int jl[1005][1005];
void dij(int x){
    for(int i=1;i<=5000;++i){
        dis[i] = 1000000000;
        v[i] = 0;
    }
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    q.push({x,0});
    dis[x] = 0;
    while(!q.empty()){
        pair<int,int> y = q.top();
        q.pop();
        int x = y.first,w = y.second;
        if(v[x]) continue;
        v[x] = 1;
        for(int i=0;i<a[x].size();++i){
            if(dis[a[x][i].first] > w+a[x][i].second){
                dis[a[x][i].first] = w+a[x][i].second;
                q.push({a[x][i].first,w+a[x][i].second});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int i=1;i<=n;++i){
        cin>>k[i];
            int x,y,z,w;
            cin>>x>>y>>z>>w;
            a[x].push_back({z,y+w});
            a[z].push_back({x,y+w});
    }
    for(int i=1;i<=n;++i){
        dij(i);
        for(int j=1;j<=n;++j){
            jl[i][j] = dis[j];
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        dij(l);
        cout<<jl[l][r]+w[l]+w[r]<<'\n';
    }
    return 0;
}
//15:32 kai ti!
//15:34 zhe sha ti mu a,zhe me rao,geng ben du bu dong
//15:40 zhong yu du dong le(ma?)
//16:10 xie le 20 fen(dij neng pao)
//20 pts
