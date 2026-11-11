#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> vx[2000005];
int c,t,n,k,vis[2000005],cnt,du[2000006];
queue<pair<int,int>> q;
bool check(int mid){
    cnt=0;
    queue<pair<int,int>> q1;
    for(int i=0;i<=n;i++) vis[i]=0;
    for(int i=1;i<=n;i++){
            if(du[i]==1){
                q.push({i,1});
            }
        }
    while(!q.empty()){
        auto g=q.front();
        q.pop();
        if(vis[g.first]) continue;
        vis[g.first]=1;
        if(g.second>mid){
            cnt++;
            if(q1.empty()) q1.push({g.first,0});
            continue;
        }
        for(auto u:vx[g.first]){
            if(vis[u]) continue;
            q.push({u,g.second+1});
        }
    }
    for(int i=0;i<=n;i++){
        vis[i]=0;
    }

    if(cnt<=k) return 1;
    else return 0;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            vx[u].push_back(v);
            vx[v].push_back(u);
            du[u]++;
            du[v]++;
        }

        int l=0,r=n;
        while(l<r){
            int mid=l+r>>1;
            if(check(mid)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        cout<<r<<'\n';
    }
    return 0;
}
