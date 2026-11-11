#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
using pii=pair<int,int>;
using pli=pair<long long,int>;
int main(){
    #ifndef PSD
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    #endif // PSD
    cin.tie(nullptr)->sync_with_stdio(false);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<vector<pii>> g((d+2)*m+1);
    vector<int> cnt(m+1,1),w(m+1);
    auto add=[&](int u,int v,int w){
        g[u].emplace_back(v,w);
    };
    int T=-1;
    bool flag=true;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        add(i,i+m,w[i]);
        add(i+m,i,w[i]);
    }
    for(int i=1,t;i<=n;i++){
        int k;
        cin>>k;
        vector<int> a(k);
        for(int&j:a){
            cin>>j>>t,++cnt[j];
            if(T==-1)T=t;
            else flag&=T==t;
            add(j+m,j+cnt[j]*m,t);
            add(j+cnt[j]*m,j+m,t);
        }
        for(int j=1;j<k;j++)
            add(a[j]+cnt[a[j]]*m,a[j-1]+cnt[a[j-1]]*m,0),
            add(a[j-1]+cnt[a[j-1]]*m,a[j]+cnt[a[j]]*m,0);
    }
    auto dijkstra=[&](int stt,vector<long long>&dis){
        dis[stt]=0;
        priority_queue<pli,vector<pli>,greater<pli>> q;
        q.emplace(0,stt);
        while(!q.empty()){
            pli t=q.top();
            q.pop();
            if(dis[t.second]!=t.first)continue;
            for(auto&j:g[t.second])
                if(dis[j.first]>t.first+j.second){
                    dis[j.first]=t.first+j.second;
                    q.emplace(dis[j.first],j.first);
                }
        }
    };
    auto bfs=[&](int stt,vector<long long>&dis){
        dis[stt]=0;
        deque<int> dq;
        vector<int> vis((d+2)*m+1);
        dq.push_back(stt);
        while(!dq.empty()){
            int t=dq.front();
            dq.pop_front();
            if(vis[t]>2)continue;
            ++vis[t];
            for(auto&j:g[t])if(j.first>m)
                if(j.second==0){
                    if(dis[j.first]>dis[t]){
                        dis[j.first]=dis[t];
                        dq.push_front(j.first);
                    }
                }
                else{
                    if(dis[j.first]>dis[t]+T){
                        dis[j.first]=dis[t]+T;
                        dq.push_back(j.first);
                    }
                }
        }
    };

    vector<vector<long long>> dis(m+1,vector<long long>(m+1,1e18));
    if(flag)for(int i=1;i<=m;i++){
        vector<long long> tdis((d+2)*m+1,1e18);
        bfs(i+m,tdis);
        for(int j=1;j<=m;j++)dis[i][j]=tdis[j]+w[i]+w[j];
    }
    else for(int i=1;i<=m;i++){
        vector<long long> tdis((d+2)*m+1,1e18);
        dijkstra(i,tdis);
        dis[i]={tdis.begin(),tdis.begin()+m+1};
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<dis[u][v]<<'\n';
    }
    return 0;
}
