#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
const int maxm=3e6+10;
long long w[maxm];
struct node{
    long long x,len;
    bool operator<(const node&a)const{
        return a.len<len;
    }
};
vector<node>G[maxm];
vector<long long>subway[maxm];
long long dist[maxm]={};
void solve(int s,int t){
    priority_queue<node>q;
    for(int i=1;i<=n+m;i++){
       dist[i]=1e18;
    }
    q.push({s,0});
    dist[s]=0;
    while(q.size()){
        int x=q.top().x;
        int d=q.top().len;
        q.pop();
        if(d>dist[x])continue;
        if(x==t){
            cout<<dist[t]+w[s]+w[t]<<endl;
            return;
        }
        for(auto &[v,len]:G[x]){
            if(dist[v]>dist[x]+len){
                dist[v]=dist[x]+len;
                q.push({v,dist[v]});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            long long a,t;
            cin>>a>>t;
            G[i+m].push_back({a,t});
            G[a].push_back({i+m,t});
        }
    }
    while(q--){
        long long x,y;
        cin>>x>>y;
        solve(x,y);
    }
    return 0;
}
