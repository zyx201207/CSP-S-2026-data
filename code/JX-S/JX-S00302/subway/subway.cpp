#define ll long long
#include<bits/stdc++.h>
using namespace std;
const int N=500010;

int c,n,m,d,q;
ll w[N],k[N],qd[1010][1010];
vector<array<ll,2>>sl[N],zd[N];


void solve(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(ll i=1;i<=n;i++){
        cin>>k[i];
        for(ll j=1,x,y;j<=k[i];j++) cin>>x>>y,sl[i].push_back({x,y}),zd[x].push_back({i,y});
    }
        priority_queue<array<ll,2>>pq;
        for(int st=1;st<=m;st++){
            for(int i=1;i<=m;i++) qd[st][i]=LLONG_MAX-10,pq.push({-qd[st][i],i});
            qd[st][st]=0,pq.push({-qd[st][st],st});
            while(!pq.empty()){
                auto [v,x]=pq.top();pq.pop();
                v=-v;
                if(v>qd[st][x]) continue;
                for(auto [i,to1]:zd[x]){
                    for(auto [j,to2]:sl[i]) if(j!=x&&qd[st][j]>qd[st][x]+to1+to2) qd[st][j]=qd[st][x]+to1+to2,pq.push({-qd[st][j],j});
                }
            }
        }
        while(q--){
            int s,t;
            cin>>s>>t;
            cout<<qd[s][t]+w[s]+w[t]<<"\n";
        }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--) solve();
}
