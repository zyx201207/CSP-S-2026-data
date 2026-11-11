#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d,u,x[2000010],t,c,f[2000010],ans;
const ll INF=1e17;
struct lll{
ll u,w;
bool operator<(const lll &x)const {return x.w < w;}
};
vector<ll>G[2000010];
vector<ll> dij(ll st){
priority_queue<lll>Q;
vector<ll>dis(n+5,INF);
Q.push({st,0});
dis[st]=0;
while(Q.size()){
    u=Q.top().u;
    Q.pop();
    for(auto &v:G[u]){
        if(dis[v]>dis[u]+1){
        dis[v]=dis[u]+1;
        Q.push({v,dis[v]});
        }
    }
}
return dis;
}
vector<ll>Dis(2000005);
ll Dij(ll st){
priority_queue<lll>Q;
vector<ll>dis(n+5,INF);
vector<ll>p(n+5,0);
Q.push({st,0});
dis[st]=0;
while(Q.size()){
    u=Q.top().u;
    Q.pop();
    for(auto &v:G[u]){
        if(dis[v]>=dis[u]+1){
        dis[v]=dis[u]+1;
        if(dis[v]==Dis[v]) p[v]++;
        Q.push({v,dis[v]});
        }
    }
}
ll Ans=0;
for(int i=1;i<=n;i++){
    if(p[i]==2) Ans++;
}
return Ans;
}
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
cin >> c >> t;
while(t--){
    ans=0;
    cin >> n >> d;
    for(int i=1;i<=n;i++)cin >> x[i];
    for(int i=1,j;i<=n;i++){
        j=i+1;
        G[i].clear();
        for(;x[j]<=x[i]+d&&j<=n;j++){
            G[i].push_back(j);
        }
    }
    for(int i=1;i<=n;i++){
        Dis=dij(i);
        ans+=Dij(i);
    }
    cout << ans << endl;
}
return 0;
}
