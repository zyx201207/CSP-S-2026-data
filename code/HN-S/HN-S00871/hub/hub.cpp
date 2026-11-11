#include<bits/extc++.h>
using namespace std;
const int N=2e6+10,N_=40;

int n,k;
vector<int> g[N];

bool vis[N_];
int dis[N_][N_];
vector<int> h[N_];
int b_cnt,b_id[N_];
int ans;

void Bfs(int s){
    for(int i=1;i<=n;++i) vis[i]=0;
    vis[s]=1;
    queue<int> q; q.push(s);
    while(q.size()){
        int x=q.front(); q.pop();
        for(auto& y:g[x]){
            if(vis[y]) continue;
            vis[y]=1; dis[s][y]=dis[s][x]+1;
            q.push(y);
        }
    }
}

void Find(int x){
    b_id[x]=b_cnt;
    for(auto& y:h[x]){
        if(b_id[y]) continue;
        Find(y);
    }
}

bool Check(){
    int cnt=0;
    for(int i=1;i<=n;++i){
        if(vis[i]){
            ++cnt;
        }
    }
    if(cnt!=k) return 0;
    for(int i=1;i<=n;++i) h[i].clear();
    for(int x=1;x<=n;++x){
        if(vis[x]){
            for(auto& y:g[x]){
                if(vis[y]){
                    h[x].push_back(y);
                }
            }
        }
    }
    b_cnt=0;
    for(int i=1;i<=n;++i) b_id[i]=0;
    for(int i=1;i<=n;++i){
        if(vis[i]&&!b_id[i]){
            ++b_cnt;
            if(b_cnt>2) return 0;
            Find(i);
        }
    }
    return 1;
}

void Calc(){
    int r=0;
    for(int i=1;i<=n;++i){
        int d;
        if(vis[i]) d=0;
        else{
            d=INT_MAX;
            for(int j=1;j<=n;++j){
                if(vis[j]){
                    d=min(d,dis[i][j]);
                }
            }
        }
        r=max(r,d);
    }
    ans=min(ans,r);
}

void Dfs(int pos){
    if(pos>n){
        if(Check()) Calc();
        return;
    }
    vis[pos]=0;
    Dfs(pos+1);
    vis[pos]=1;
    Dfs(pos+1);
}

void Solve1(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j) dis[i][j]=0;
        Bfs(i);
    }
    ans=INT_MAX;
    Dfs(1);
    cout<<ans<<"\n";
}

int main(){
    auto ___=freopen("hub.in","r",stdin);
    auto _=freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c,t; cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;++i) g[i].clear();
        for(int i=1;i<n;++i){
            int x,y; cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        Solve1();
    }
    
    return 0;
}

// g++ hub.cpp -O2 -std=c++14 -static -o test.exe
// ./test.exe < hub.in > test.out
// diff test.out hub.ans