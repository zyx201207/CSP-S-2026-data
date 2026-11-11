//CSP-S 2026 RP++!
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::ios;
using std::vector;
using std::pair;
using std::priority_queue;

#define int long long
#define pii pair<int,int>
#define fi first
#define se second

const int N=5e5+5,NN=5e2+5,Q=2*N+NN,CN=1e3+5;

struct pq_nodes{
    int to,val;

    bool operator< (const pq_nodes &a)const{
        return val>a.val;
    }
};

int c,n,m,d,q,u,v,tim;
int dis[Q],flag[Q];

vector<pii> vec[N],has[N];

int query(int st,int ed,int tim){
    memset(dis,-1,sizeof dis);
    priority_queue<pq_nodes> que;
    que.push({st,0}),dis[st]=0;
    while(!que.empty()){
        auto now=que.top();
        que.pop();
        if(now.to==ed)
            return now.val;
        if(flag[now.to]==tim)
            continue;
        flag[now.to]=tim;
        for(auto ne:vec[now.to]){
            if(flag[ne.fi]==tim)
                continue;
            if(dis[ne.fi]==-1||dis[ne.fi]>dis[now.to]+ne.se)
                dis[ne.fi]=dis[now.to]+ne.se,que.push({ne.fi,dis[ne.fi]});
        }
    }
    return -1;
}

void solve(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1,w;i<=m;i++){
        cin>>w;
        vec[i].push_back({i+m,w});
        vec[i+m].push_back({i,w});
    }
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,u,val;j<=k;j++){
            cin>>u>>val;
            has[u].push_back({2*m+i,val});
            vec[u+m].push_back({2*m+i,val});
            vec[2*m+i].push_back({u+m,val});
        }
    }
    for(int i=1;i<=m;i++){
        for(auto j:has[i]){
            for(auto k:has[i]){
                if(j.fi==k.fi)continue;
                vec[j.fi].push_back({k.fi,j.se+k.se});
            }
        }
    }
    while(q--){
        cin>>u>>v;
        cout<<query(u,v,++tim)<<'\n';
    }
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}
