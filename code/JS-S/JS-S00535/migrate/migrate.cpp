// Migrate
// migrate.cpp
#include<bits/stdc++.h>
using namespace std;
#define LOGGER 1
#if LOGGER == 1
#define LOG(k) k
#else
#define LOG(k)
#endif
typedef long long sll;
typedef unsigned long long ull;
constexpr int N=2e6+5;
int C,T;
int n,d;
int x[N];
vector<int> access[N];
int ans=0;
void getroute(int fr,int to,int pre_d,int &mind,int &cnt){
    if(fr>to)return;
    if(fr==to){
        if(mind>pre_d){
            cnt=1;mind=pre_d;
        }else if(mind==pre_d){
            cnt++;
        }
        return;
    }
    for(auto &t:access[fr]){
        if(pre_d>mind)return;
        getroute(t,to,pre_d+1,mind,cnt);
    }
}
void solve2(int piv=1){
    if(piv>=n)return;
    for(int k=piv+1;k<=n;k++){
        int mind=n,cnt=0;
        getroute(piv,k,0,mind,cnt);
        if(cnt==2)ans++;
        // LOG(cerr<<"At "<<piv<<","<<k<<" find "<<cnt<<endl;)
    }
    solve2(piv+1);
}
int dis[N];
int vis[N];
struct Edge{
    int fr;int to;int w;
};
bool operator<(const Edge& ref1,const Edge& ref2){
        return false;
}
void find(int so){
    priority_queue<Edge> que;
    que.push({1,1,0});
    for(int i=1;i<=n;i++){
        vis[i]=0;
        dis[i]=2147483647;
    }
    dis[so]=0;
    while(!que.empty()){
        auto e=que.top();que.pop();
        for(auto &ed:access[e.to]){
            if(dis[e.to]+1<dis[ed]){
                dis[ed]=dis[e.to]+1;
                vis[e.to]=1;
                que.push({e.to,ed,1});
            }
            if(dis[e.to]+1==dis[ed]){
                que.push({e.to,ed,1});
                vis[e.to]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==2)ans++;
    }
}
void solve(int piv=1){
    if(piv>=n)return;
    find(piv);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    // LOG(cerr<<"Starting test."<<endl;)
    cin>>C>>T;
    for(int t=1;t<=T;++t){
        cin>>n>>d;
        for(int i=1;i<=n;++i){
            cin>>x[i];
            access[i].clear();
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]>d)break;
                access[i].push_back(j);
            }
            reverse(access[i].begin(),access[i].end());
        }
        ans=0;
        solve2();
        cout<<ans<<endl;
    }
    return 0;
}
