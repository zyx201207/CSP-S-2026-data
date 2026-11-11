#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans;
int w[500010],k[510],a[510][500010],t[510][500010];
bool vis[500010];
vector<int>h[500010];
void dfs(int ti,int x,int y){
    if(x==y){
        ans=min(ans,ti+w[y]);
        return;
    }
    for(auto i:h[x]){
        for(int j=1;j<=k[i];j++){
            if(vis[a[i][j]]==0){
                vis[a[i][j]]=1;
                dfs(ti+t[i][x]+t[i][a[i][j]],a[i][j],y);
                vis[a[i][j]]=0;
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][a[i][j]];
            h[a[i][j]].push_back(i);
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ans=INT_MAX;
        dfs(w[x],x,y);
        cout<<ans<<endl;
    }
    return 0;
}
