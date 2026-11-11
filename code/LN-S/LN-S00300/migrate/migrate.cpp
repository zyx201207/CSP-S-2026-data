#include<bits/stdc++.h>
using lli=long long;
using ull=unsigned long long;
using namespace std;
const int N=200005;
int c,t;
lli x[N];
vector<int> g[N];
int dis[N];
bool yes[N];
bool tri[N];
bool vis[N];
bool inq[N];
void bfs_0(int s){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v:g[u]){
            if(!dis[v]){
                dis[v]=dis[u]+1;
                q.push(v);
            }else if(dis[v]==dis[u]+1){
                if(yes[v])tri[v]=1;
                yes[v]=1;
            }
        }
    }
}
void bfs_1(int s){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v:g[u]){
            yes[v]=yes[v]||yes[u];
            tri[v]=tri[v]||tri[u];
            if((yes[v]||tri[v])&&!inq[v]){
                q.push(v);
                inq[v]=1;
            }
        }
    }
}
void solve_0(){
    int n;
    ull d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        g[i].clear();
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if((ull)(x[j]-x[i])<=d){
                g[i].push_back(j);
            }else{
                break;
            }
        }
    }
    int ans=0;
    for(int i=1;i<n;i++){
        for(int j=i;j<=n;j++){
            dis[j]=0;yes[j]=0;vis[j]=0;inq[j]=0;tri[j]=0;
        }
        bfs_0(i);
        bfs_1(i);
        for(int j=i+1;j<=n;j++){
            //cout<<dis[j]<<" ";
            ans+=(yes[j]&&!tri[j]);
        }
        //cout<<"\n";
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        if(c<=10){
            solve_0();
        }
    }
}
//Your determination break outed.
