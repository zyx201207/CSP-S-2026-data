#include<bits/stdc++.h>
using namespace std;
using Pii=pair<int,int>;
const int kMaxN=1e6+5;
int CCC,T,n,k,d[kMaxN],minn,dis[kMaxN];
bool f[kMaxN];
vector<int> s[kMaxN],ys;
int F(int x){
    return d[x]==x?x:d[x]=F(d[x]);
}
bool C(){
    for(int i=1;i<=n;i++) d[i]=i;
    for(int i:ys){
        for(int j:s[i]){
            if(!f[j]) continue;
            int xx=F(i),yy=F(j);
            if(xx!=yy) d[xx]=yy;
        }
    }
    set<int> tot;
    tot.clear();
    for(int i:ys) tot.insert(F(i));
    if(tot.size()>2) return false;
    return true;
}
priority_queue<Pii,vector<Pii>,greater<Pii>> pq;
void S(){
    for(int i=1;i<=n;i++) dis[i]=1e9;
    for(int i:ys) pq.push({0,i});
    while(!pq.empty()){
        Pii p=pq.top();
        pq.pop();
        if(dis[p.second]<=p.first) continue;
        dis[p.second]=p.first;
        for(int i:s[p.second]){
            pq.push({p.first+1,i});
        }
    }
    int tqbj=0;
    for(int i=1;i<=n;i++){
        tqbj=max(tqbj,dis[i]);
    }
    minn=min(minn,tqbj);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    for(cin>>CCC>>T;T;T--){
        cin>>n>>k;
        minn=1e9;
        for(int i=1;i<=n;i++) s[i].clear();
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            s[u].push_back(v);
            s[v].push_back(u);
        }
        for(int x=0;x<(1<<n);x++){
            int cnt=0;
            ys.clear();
            for(int i=1;i<=n;i++) f[i]=0;
            for(int i=0;i<n;i++){
                if((x>>i)&1) cnt++,ys.push_back(i+1),f[i+1]=1;
            }
            if(cnt!=k) continue;
            if(!C()) continue;
            S();
        }
        cout<<minn<<'\n';
    }
    return 0;
}