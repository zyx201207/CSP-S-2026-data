#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define fir first
#define sec second
using namespace std;
const int N=2e6+7;
int n,d;
int a[N];
vector<int> g[N];
int dis[N];
int way[N];
void bfs(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(way,0,sizeof(way));
    priority_queue<pair<int,int>> q;
    dis[s]=0;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().sec;q.pop();
        cerr<<u<<endl;
        for(auto v:g[u]){
            if(dis[u]+1<dis[v]){
                dis[v]=dis[u]+1,way[v]=1;
                q.push({-dis[v],v});
            }
            else if(dis[u]+1==dis[v])
                way[v]++;
        }
    }
}
void mian(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        auto it=lower_bound(a+i,a+n+1,a[i]+d);
        if(it==a+n+1)
            it=a+n;
        int id=it-a;
        for(int j=i+1;j<=id;j++)
            g[i].push_back(j);
    }
    
    int ans=0;
    for(int i=1;i<=n;i++){
        bfs(i);
        for(int j=1;j<=n;j++)
            ans+=(way[j]==2);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int _77231=1,c;
    cin>>c>>_77231;
    while(_77231--)mian();
    return 0;
}