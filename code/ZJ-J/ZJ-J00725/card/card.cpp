#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],pos[500010];
int rt[500010];
vector<int> e[500010];
int sz[500010];
void dfs(int x){
    sz[x]=1;
    for(int v:e[x]) dfs(v),sz[x]+=sz[v];
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    pos[a[n]]=n,rt[a[n]]=n;
    for(int i=n-1;i>=1;i--){
        if(!pos[a[i]]) rt[a[i]]=i,e[i+1].push_back(i);
        else e[pos[a[i]]].push_back(i);
        pos[a[i]]=i;
    }
    dfs(n);
    for(int i=1;i<=m;i++) cout<<sz[rt[i]]<<" ";
    return 0;
}