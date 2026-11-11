#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e3+5;
int c,t,n;
ll x[N],d,dis[N],cnt[N];
vector<int> e[N];
struct node{
    int pos;
    ll time;
};
queue<node> S;
ll bfs(int x){
    S.push({x,0});
    memset(dis,0x7f,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    while(!S.empty()){
        int u=S.front().pos;
        ll time=S.front().time;
        S.pop();
        for(auto v:e[u]){
            if(dis[v]>=time+1){
                dis[v]=time+1;
                cnt[v]++;
                S.push({v,time+1});
            }
        }
    }
    ll res=0;
    for(int i=1;i<=n;i++) if(cnt[i]==2) res++;
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            e[i].clear();
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n && x[j]-x[i]<=d;j++){
                e[i].push_back(j);
            }
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            ans+=bfs(i);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
