#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int len=2e6+5;
struct node{
    int u,w;
};
ll c,T,n,d,x[len],dis[len],cnt[len];
ll ans;
void bfs(int s){
    queue<node> q;
    q.push({s,1});
    dis[s]=1;
    while(q.size()){
        node t=q.front();
        ll u=t.u,w=t.w;
        q.pop();
        if(dis[u]!=0&&w>dis[u]) continue;
        dis[u]=w;
        if(dis[u]==w) cnt[u]++;
        for(int i=u+1;i<=n;i++){
            if(x[i]-x[u]>d) break;
            q.push({i,w+1});
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++){
            for(int i=1;i<=n;i++){
                if(cnt[i]==2) ans++;
                dis[i]=0,cnt[i]=0;
            }
            bfs(i);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
