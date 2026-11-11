#include<bits/stdc++.h>
#define pipii pair<long long,pair<int,pair<int,int>>>
using namespace std;
int c,n,m,D,Q;
int mst[500005];
vector<int>g[500005][21];
int w[500005][21];
long long d[500005];
long long dij(int st,int ed){
    cout<<st<<" "<<ed<<"*\n";
    for(int i=1;i<=m;i++){
        d[i]=1e18;
    }
    priority_queue<pipii,vector<pipii>,greater<pipii>>q;
    q.push({(long long)mst[st],{0,{0,st}}});
    d[st]=0;
    while(!q.empty()){
        pipii tt=q.top();
        q.pop();
        long long dis=tt.first;
        int rt=tt.second.first,lst=tt.second.second.first,u=tt.second.second.second;
        cout<<lst<<" "<<u<<" "<<rt<<" "<<dis<<"\n";
        if(u==ed){
            return dis+w[u][rt]+mst[u];
        }
        if(u!=1&&d[u]<dis+w[u][rt]){
            continue;
        }
        for(int i=1;i<=D;i++){
            if(i==rt){
                for(int v:g[u][i]){
                    if(v==lst){
                        continue;
                    }
                    if(d[v]>dis+w[v][i]){
                        d[v]=dis+w[v][i];
                        q.push({dis,{i,{u,v}}});
                    }
                }
            }
            for(int v:g[u][i]){
                if(v==lst){
                    continue;
                }
                if(d[v]>dis+w[u][rt]+w[u][i]+w[v][i]){
                    d[v]=dis+w[u][rt]+w[u][i]+w[v][i];
                    q.push({dis+w[u][rt]+w[u][i],{i,{u,v}}});
                }
            }
        }
    }
    return 0ll;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>D>>Q;
    for(int i=1;i<=m;i++){
        cin>>mst[i];
    }
    for(int i=1;i<=n;i++){
        int K;
        cin>>K;
        int lst=0;
        for(int j=1;j<=K;j++){
            int u,wt;
            cin>>u>>wt;
            w[u][i]=wt;
            if(lst!=0){
                g[u][i].push_back(lst);
                g[lst][i].push_back(u);
            }
            lst=u;
        }
    }
    for(int i=1;i<=Q;i++){
        int st,ed;
        cin>>st>>ed;
        cout<<dij(st,ed)<<"\n";
    }
    return 0;
}
