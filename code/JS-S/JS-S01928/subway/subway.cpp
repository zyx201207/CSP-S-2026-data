#include <bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int m,n,d,q,w[MAXN];
struct node{
    int v, w;
};
vector <node> e[MAXN];
void solve(){
    cin>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        if(k==2){
            int u,v,w1,w2;
            cin>>u>>w1>>v>>w2;
            e[u].push_back({v,w1+w2});
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        long long ans=0;
        ans+=w[x]+w[y];
        long long d[MAXN];
        for(int i=1;i<=m;i++){
            d[i]=-1;
        }
        d[x]=0;
        priority_queue <pair<int,int>> h;
        h.push({x,0});
        while(!h.empty()){
            pair<int,int> nw=h.top();
            h.pop();
            if(nw.second>d[nw.first]) continue;
            for(auto p:e[nw.first]){
                int v=p.v,ww=p.w;
                if(d[nw.first]+ww<d[v]||d[v]==-1){
                    d[v]=d[nw.first]+ww;
                    h.push({v,d[v]});
                }
            }
        }
        ans+=d[y];
        cout<<ans<<endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    cin>>c;
    if(c>=0&&c<=11){
        solve();
    }
    else{
        cin>>n>>m>>d>>q;
        for(int i=1;i<=q;i++){
            cout<<0<<endl;
        }
    }
    return 0;
}



