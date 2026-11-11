#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6+5;
int c,n,m,d,q;
int w[N];
struct node
{
    int to,w;
}e[N];
vector<node>v[N];
int a[N],t[N],ans=1e9,vis[N];
void dfs(int st,int ed,int sum)
{
    if(sum>=ans)return;
    if(st==ed){
        ans=min(ans,sum);
        return;
    }
    for(node i : v[st]){
        if(vis[i.to])continue;
        vis[i.to]=1;
        dfs(i.to,ed,sum+w[i.to]+i.w);
        vis[i.to]=0;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int lst=0;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        for(int j=1;j<k;j++){
//            cout<<a[j]<<" "<<a[j+1]<<'\n';
            v[a[j]].push_back({a[j+1],t[j]});
            v[a[j+1]].push_back({a[j],t[j+1]});
        }
    }
    while(q--){
        memset(vis,0,sizeof(vis));
        int x,y;
        cin>>x>>y;
        ans=1e18;
        dfs(x,y,0);
        cout<<ans<<'\n';
    }
    return 0;
}

