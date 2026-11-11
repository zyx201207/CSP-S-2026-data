#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
int Testid,T;
int n;
ll d;
ll a[N];
bool vis[N];
ll dis[N];
ll cnt[N];
ll ans;
vector<int>G[N];
queue<int>q;
void bfs(int s){
    for(int i=1;i<=n;i++){
        vis[i]=0;
        dis[i]=INF;
        cnt[i]=0;
    }
    q.push(s);
    dis[s]=0;
    cnt[s]=1;
    //cout<<"Start: "<<s<<"\n";
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        if(vis[u])continue;
        if(cnt[u]>2)continue;
        vis[u]=1;
        //cout<<u<<": \n";
        for(auto v:G[u]){
            //cout<<v<<" "<<dis[v]<<" "<<dis[u]<<" "<<cnt[v]<<" "<<cnt[u]<<"\n";
            if(dis[v]>dis[u]+1){
                q.push(v);
                dis[v]=dis[u]+1;
                cnt[v]=cnt[u];
            }else if(dis[v]==dis[u]+1){
                cnt[v]+=cnt[u];
            }
        }
        //cout<<"\n";
    }
}
void init(int n){
    ans=0;
    for(int i=1;i<=n;i++){
        G[i].clear();
    }
}
int main(){
    //freopen("/home/user/Desktop/migrate/migrate5.in","r",stdin);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>Testid>>T;
    while(T--){
        cin>>n>>d;
        init(n);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    G[i].push_back(j);
                }else{
                    break;
                }
            }
        }
        //for(int i=1;i<=n;i++){
        //    for(auto j:G[i]){
        //        cout<<j<<" ";
        //    }
        //    cout<<"\n";
        //}
        for(int i=1;i<=n;i++){
            bfs(i);
            //cout<<i<<":\n";
            for(int j=i+1;j<=n;j++){
                //cout<<j<<" "<<dis[j]<<" "<<cnt[j]<<"\n";
                if(cnt[j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
