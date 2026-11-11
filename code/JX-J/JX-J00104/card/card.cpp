#include <iostream>
#include <vector>
using namespace std;
long long n,m,a[500005],last[300005],ans[500005],cnt[300005];
vector<int> g[500005];
long long sz[500005];
void dfs(int u){
    sz[u]=1;
    for(int v:g[u]){
        dfs(v);
        sz[u]+=sz[v];
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        if(last[a[i]]==0){
            ans[i]=i+1;
            last[a[i]]=i;
        }else{
            ans[i]=last[a[i]]+1;
        }
        g[ans[i]].push_back(i);
    }
    dfs(n+1);
    for(int i=1;i<=n;i++){
        cnt[a[i]]+=sz[i];
        //cout<<last[a[i]]<<' ';//
        //cout<<sz[i]<<' ';//
        //cout<<ans[i]<<' ';//
    }
    //cout<<'\n';//
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
