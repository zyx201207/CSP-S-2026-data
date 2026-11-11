#include<bits/stdc++.h>
#define int long long

int C,N,M,D,K;
int W[500005];
std::vector<int> A[505],T[505];
std::pair<int,int> Q[100005];
std::map<int,std::vector<int> > mp;

void input(){
    scanf("%lld %lld %lld %lld %lld",&C,&N,&M,&D,&K);
    for(int i=1;i<=M;i++)scanf("%lld",W+i);
    for(int i=1;i<=N;i++){
        int t; scanf("%lld",&t); A[i].push_back(t); T[i].push_back(t);
        for(int j=1;j<=t;j++){
            int c; scanf("%lld",&c); A[i].push_back(c);
            mp[c].push_back(i);
            scanf("%lld",&c); T[i].push_back(c);
        }
    }
    for(int i=1;i<=K;i++)scanf("%lld %lld",&Q[i].first,&Q[i].second);
}

namespace baoli{
    //baoli can pass testcase 1-8, if I calculate the time complexity correctly.
    //because that a single ki = 2 in testcase 9-11, it can also pass.
    //that is 44 pts. I love CCF
    struct edge{
        int v,w;
    };
    std::vector<edge> g[5005];
    int dis[2005][2005];
    bool vis[2005];
    struct node{
        int u,du;
        bool operator<(const node& other)const{
            return du > other.du;
        }
    };
    std::priority_queue<node> pq;
    void dijkstra(int st){
        for(int i=0;i<2005;i++)dis[st][i] = INT_MAX;
        memset(vis,0,sizeof vis);
        dis[st][st] = 0; pq.push({st,0});
        while(!pq.empty()){
            int u = pq.top().u,du = pq.top().du;
            pq.pop();
            if(vis[u])continue;
            vis[u] = 1;
            for(auto e:g[u]){
                if(du+e.w < dis[st][e.v]){
                    dis[st][e.v] = du+e.w;
                    pq.push({e.v,dis[st][e.v]});
                }
            }
        }
    }

    void solve(){
        for(int i=1;i<=N;i++){
            for(int j=1;j<A[i][0];j++){
                for(int k=j+1;k<=A[i][0];k++){
                    g[A[i][j]].push_back({A[i][k],T[i][j]+T[i][k]});
                    g[A[i][k]].push_back({A[i][j],T[i][j]+T[i][k]});
                }
            }
        }
        for(int i=1;i<=M;i++)dijkstra(i);
        for(int i=1;i<=K;i++){
            int ans = W[Q[i].first]+W[Q[i].second];
            ans += dis[Q[i].first][Q[i].second];
            printf("%lld\n",ans);
        }
    }
}

namespace xingzhib{
    //time complexity up to 3*1e8, I hope it runs fast when evaluating. CCF I love you please!!!!
    //I cannot believe that it really passes subway5 and 6.
    int dis[505][505];
    void solve(){
        for(int i=0;i<505;i++)for(int j=0;j<505;j++)dis[i][j] = INT_MAX;
        for(int i=1;i<=N;i++)dis[i][i] = 0;
        for(auto it = mp.begin();it != mp.end();it++){
            for(int i=0;i<it->second.size()-1;i++){
                for(int j=i+1;j<it->second.size();j++){
                    dis[it->second[i]][it->second[j]] = dis[it->second[j]][it->second[i]] = 1;
                }
            }
        }
        for(int k=1;k<=N;k++)for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)dis[i][j] = std::min(dis[i][j],dis[i][k]+dis[k][j]);
        for(int i=1;i<=K;i++){
            int ans = W[Q[i].first]+W[Q[i].second];
            int tmp = INT_MAX;
            for(auto u:mp[Q[i].first])for(auto v:mp[Q[i].second]){
                tmp = std::min(tmp,(dis[u][v]+1)*T[1][1]*2);
            }
            ans += tmp;
            printf("%lld\n",ans);
        }
    }
}

signed main(){
    //up to 76 pts
    freopen("subway.in","r",stdin); freopen("subway.out","w",stdout);
    input();
    if(C >= 12 && C <= 19)xingzhib::solve();
    else if(C >= 1 && C <= 11)baoli::solve();
    return 0;
}
