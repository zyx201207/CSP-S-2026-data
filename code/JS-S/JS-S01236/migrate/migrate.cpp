#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e6+7,inf=0x3f3f3f3f;
int n;
ll d,a[N],f[N],cnt[N];
int dist[N];
bool vis[N];
inline bool dijkstra(int s,int e){
    memset(dist,0x3f,sizeof(dist));
    memset(vis,false,sizeof(vis));
    memset(f,0,sizeof(f));
    dist[s]=0,f[s]=1;
    priority_queue<pii,vector<pii>,greater<pii> >q;
    q.push({0,s});
    while(!q.empty()){
        int x=q.top().second;
        q.pop();
        if(vis[x]){
            continue;
        }
        vis[x]=true;
        for(int i=x+1;i<=n&&a[i]-a[x]<=d;i++){
            if(vis[i]){
                continue;
            }
            int newdist=dist[x]+1;
            if(newdist<dist[i]){
                dist[i]=newdist;
                f[i]=f[x];
                q.push({dist[i],i});
            }else if(newdist==dist[i]){
                f[i]++;
            }
        }
    }
    return f[e]==2;
}
inline void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans+=dijkstra(i,j);
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
