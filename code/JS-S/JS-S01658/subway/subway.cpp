#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505,M = 2e4+5;
int c,n,m,di,T;
ll k[N],a[N][M];
ll w[M],t[N][M];
struct node{
    int id;
    ll y,z;
    friend bool operator<(node t,node tt){
        return t.z > tt.z;
    }
};
struct pos{
    int id,p;
};
priority_queue<node>q;
vector<pos>b[N];
ll d[N][M];
int v[N][M];
ll dij(int s,int ed){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) d[i][j] = 1e18,v[i][j] = 0;
    }
    while(q.size()) q.pop();
    for(pos i:b[s]){
        d[i.id][s] = t[i.id][i.p];
        q.push({i.id,s,0});
    }
    while(q.size()){
        int x = q.top().y,id = q.top().id;q.pop();
        if(v[id][x]) continue;
        v[id][x] = 1;int p1;
        for(int i = 0;i < b[x].size();i++){
            int y = b[x][i].id;
            if(id == y){
                p1 = b[x][i].p;
                break;
            }
        }
        for(int i = 0;i < b[x].size();i++){
            int y = b[x][i].id,p = b[x][i].p;ll z = t[y][p]+t[id][p1];
            if(id == y) continue;
            if(d[y][x] > d[id][x]+z){
                d[y][x] = d[id][x]+z;
                q.push({y,x,d[y][x]});
            }
        }
        for(int i = 1;i <= k[id];i++){
            int y = a[id][i];
            if(x == y) continue;
            if(d[id][y] > d[id][x]){
                d[id][y] = d[id][x];
                q.push({id,y,d[id][y]});
            }
        }
    }
    ll ans = 1e18;
    for(pos i:b[ed]) ans = min(ans,d[i.id][ed]+w[s]+w[ed]+t[i.id][i.p]);
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> di >> T;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++){
        cin >> k[i];
        for(int j = 1;j <= k[i];j++) cin >> a[i][j] >> t[i][j];
        for(int j = 1;j <= k[i];j++) b[a[i][j]].push_back({i,j});
    }
    while(T--){
        int x,y;cin >> x >> y;
        cout << dij(x,y) << "\n";
    }
    return 0;
}


//I can't wait no mistake
//I'm in love like a drug
//pick me up these feelings
//will never leave my heart
//love me love me
//该考生代码耗时2.5h
