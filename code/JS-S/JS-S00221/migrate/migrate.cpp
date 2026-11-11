#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e6+10;
int c,_,n;
ll d,x[maxn],ans;
vector<int> T[maxn];
void init(){
    for(int i=1;i<=n;i++){
        T[i].clear();
    }
    ans=0;
}
ll dis[maxn],cnt[maxn];
int vis[maxn];
void bfs(int s){
    queue<int> q;
    dis[s]=1;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:T[u]){
            if(dis[v]){
                if(dis[u]+1==dis[v])cnt[v]++;
                continue;
            }
            cnt[v]++;
            dis[v]=dis[u]+1;
            q.push(v);
        }
    }
}
void bfsl(int s){
    queue<int> q;
    vis[s]=1;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:T[u]){
            if(cnt[u]==2&&cnt[v]==1&&dis[v]==dis[u]+1)cnt[v]=2;
            if(vis[v]){
                continue;
            }
            q.push(v);
            vis[v]=1;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>_;
    while(_--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        init();
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(i==j)continue;
                if(x[j]-x[i]>d)break;
                T[i].push_back(j);
                T[j].push_back(i);
            }
        }
        for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                        dis[j]=0;
                        cnt[j]=0;
                        vis[j]=0;
                }
                bfs(i);
                bfsl(i);
                for(int j=1;j<=n;j++){
                    if(cnt[j]==2){
                           // cout<<i<<" "<<j<<'\n';
                            ans++;
                    }
                }
        }
        cout<<ans/2<<'\n';
    }
    return 0;
}
