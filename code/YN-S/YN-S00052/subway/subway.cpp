#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,ans,res;
int w[N],k[N];
struct node{
    int id,tm;
}k[500][500];
struct sub{
    int way,val;
    bool operator<(const sub &b)const{
        return b.val>val;
    }
};
priority_queue<sub>q[N];
vector<int>g[N];
bool vis[N];
void dfs(int now,int y,int cnt){
    if(now==y){
        res=min(res,cnt);
        return;
    }
    for(int i:v[now]){
        if(vis[i]==1) continue;
        vis[i]=1;
        dfs(i,now,cnt);
        vis[i]=0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j].id>>a[i][j].tm;
            q[a[i][j].id].push({k[i],a[i][j].tm});
            if(j>=1){
                int u=a[i][j].id;
                int v=a[i][j-1].id;
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ans=w[x]+w[y];
        //dfs(x,y,0);
        ans+=res;
        cout<<ans<<"\n";
    }
    return 0;
}
