#include<bits/stdc++.h>
using namespace std;
// #define int long long

int fa[1005];
void init(int n){
    for(int i=0;i<n+5;i++){
        fa[i]=i;
    }
}
int fnd_fa(int x){
    if(fa[x]!=x){
        fa[x]=fnd_fa(fa[x]);
        return fa[x];
    }
    return x;
}

void unite(int x,int y){
    fa[fnd_fa(x)]=fnd_fa(y);
}

struct edge{
    int v,w;
};

vector<vector<edge>>g;
vector<vector<edge>>g1;
int dis[500005];
void dij(int s){
    memset(dis,0x3f,sizeof(dis));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    dis[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        auto i=pq.top();
        int d=i.first;
        int u=i.second;

        pq.pop();
        if(d!=dis[u]){
            continue;
        }
        for(auto j:g1[u]){
            int v=j.v;
            int w=j.w;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        // vector<vector<int>>g(n+1);
        g.clear();
        g.resize(n+1);
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back({v,1});
            g[v].push_back({u,1});
        }
        if(k==2){
            cout<<1<<"\n";
            // cout<<endl;
            continue;
        }
        int ans=0x3f3f3f3f;
        for(int i=0;i<(1<<(n+1));i++){
            bitset<11>chs(i);
            int cnt=0;
            for(int i=0;i<n;i++){
                if(chs[i]){
                    cnt++;
                }
            }
            if(cnt!=k){
                continue;
            }
            init(n);
            vector<int>cc;
            for(int i=0;i<n;i++){
                if(chs[i]==1){
                    cc.push_back(i+1);
                }
            }
            for(auto i:cc){
                for(auto j:g[i]){
                    unite(i,j.v);
                }
            }
            set<int>ct;
            for(auto i:cc){
                ct.insert(fnd_fa(i));
            }
            if(ct.size()>2){
                continue;
            }
            int tt=0;
            g1.clear();
            g1=g;
            // g1.resize(n+1);
            // for(int xx=1;xx<=n;xx++){
            //     auto i=g[xx];
            //     for(auto j:i){
            //         // bool flg=0;
            //         for(auto x:cc){
            //             if(fnd_fa(x)==fnd_fa(xx)&&fnd_fa(xx)==fnd_fa(j.v)){
            //                 j.w=0;
            //             }
            //         }
            //         g1[xx].push_back({j.v,j.w});
            //         g1[j.v].push_back({xx,j.w});
            //     }
            // }
            for(int i=1;i<=n;i++){
                dij(i);
                // cout<<i<<' ';
                for(int j=1;j<=n;j++){
                    if(fnd_fa(i)!=fnd_fa(j)&&i!=j){
                        // cout<<1<<endl;
                        tt=max(dis[j],tt);
                        
                    }
                }
            }
            // cout<<tt<<endl;
            // cout<<endl;
            // cout<<ans<<endl;
            ans=min(ans,tt);
            
            // cout<<endl;
        }
        cout<<ans<<endl;
    }
    // cout<<endl;
    return 0;
}

