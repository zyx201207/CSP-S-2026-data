#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int d,n,m,dis[N],cnt[N],a[N],flag[N];
vector<int> g[N];
void init(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
}
void bfs(int root){
    for(int i=1;i<=n;i++) dis[i]=1e18,flag[i]=0;
    queue<int> q;
    dis[root]=0,flag[root]=1,cnt[root]=1;
    q.push(root);
    flag[root]=1;
    while(q.size()){
        int u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(dis[u]+1==dis[v]) cnt[v]+=cnt[u];
            if(dis[u]+1<dis[v]) cnt[v]=cnt[u],dis[v]=dis[u]+1;
            if(!flag[v]) q.push(v),flag[v]=1;
        }
    }
}
signed main(){
    init();
    //freopen("migrate4.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        int res=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            g[i].clear();
        }
        for(int i=1;i<=n;i++){
            int j=i+1;
            while(j<=n&&a[j]-a[i]<=d) g[i].push_back(j),j++;
        }
        for(int i=1;i<=n;i++){
            bfs(i);
            for(int j=1;j<=n;j++){
                if(cnt[j]==2) res++;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}
