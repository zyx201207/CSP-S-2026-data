#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ai2 array<int,2>
using namespace std;
const int kM=5e5+5;
int c,n,m,d,q,w[kM];
vector<int>v[kM];
vector<int>s[505];
int vis[kM];
map<pii,int>ma;
priority_queue<ai2,vector<ai2>,greater<ai2>>h;/*0 distance 1 subway id */
int bfs(int b,int e){
    fill(vis,vis+m+1,1e18);
    while(!h.empty())h.pop();
    for(h.push({0,b});h.size();){
        int x=h.top()[1],d=h.top()[0];
        h.pop();
        if(vis[x]<d)continue;
        if(x==e)
            return d;
        for(int id:v[x])
            for(int j:s[id]){
                if(j!=x&&d+ma[{x,id}]+ma[{j,id}]<vis[j]){
                    vis[j]=d+ma[{x,id}]+ma[{j,id}];
                    h.push({d+ma[{x,id}]+ma[{j,id}],j});
                }
            }
    }
    return 0;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++)
        cin>>w[i];
    for(int i = 1,k;i<=n;i++){
        cin>>k;
        for(int j = 1,x,y;j<=k;j++){
            cin>>x>>y;
            v[x].push_back(i);
            s[i].push_back(x);
            ma[{x,i}]=y;
        }
    }
    for(int i = 1,b,e;i<=q;i++){
        cin>>b>>e;
        cout<<bfs(b,e)+w[b]+w[e]<<"\n";
    }
    return 0;
}

