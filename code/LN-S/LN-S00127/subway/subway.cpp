#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long c,n,m,d,qq,st,ed,mpid,id;
long long k[505],nodecnt;
long long w[500005];
long long a,t;
bool f=true;
unordered_map<long long,int>mp;
struct node{
    long long v;
    long long w;
};
vector<node>g[501005];
vector<node> aid[505];
long long dis[501005];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
void dij(ll s){
            for(auto pp:aid[mp[s]]){
            if(pp.v!=s)
                    dis[pp.v]=d+pp.w;
                    q.push({dis[pp.v],pp.v});

            }

    while(!q.empty()){
        pair<long long,long long>p=q.top();
        long long d=p.first;
        long long u=p.second;
        q.pop();

        for(auto pp:g[u]){
            if(pp.v!=u)
            if(d+pp.w<dis[pp.v]||dis[pp.v]==-1){
                dis[pp.v]=d+pp.w;
                q.push({dis[pp.v],pp.v});
            }
        }
    }
}


int main(){
    freopen("subway1.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> qq;
    for(ll i=1;i<=m;i++){
        cin >> w[i];
    }
    for(ll i=1;i<=n;i++){
        cin >> k[i];
        ++mpid;
        ++nodecnt;
        for(ll j=1;j<=k[i];j++){
            cin >> a >> t;
            if(mp.count(a)){
                    for(auto ttt:aid[mp[a]]){
                            if(ttt.v==mpid)continue;
                        g[mpid].push_back({ttt.v,ttt.w+t});
                        g[ttt.v].push_back({mpid,ttt.w+t});
                    }
            }
            if(!mp.count(a))mp[a]=++id;
            aid[mp[a]].push_back({mpid,t});
        }
    }

    for(ll i=1;i<=qq;i++){
        cin >> st >> ed;
        long long ans=1000000005;
        for(int i=1;i<=nodecnt;i++)dis[i]=-1;
        dij(st);
        for(auto ttt:aid[ed]){
            ans=min(ans,ttt.w+dis[ttt.v]);
        }
        ans+=w[st]+w[ed];
        cout << ans << "\n";
    }
    return 0;
}
