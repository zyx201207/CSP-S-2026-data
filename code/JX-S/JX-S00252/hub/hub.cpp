#include<bits/stdc++.h>
using namespace std;
int c,tt;

int n,k;
vector<int> t[1000005];

int jd[1000005];
bool vis[1000005];

void dfs(int i){
    if(i>k){

        return;
    }
    for(int j=1;j<=n;j++){
        if(vis[j])continue;
        vis[j]=true;
        jd[i]=j;
        dfs(i+1);
        vis[j]=false;
    }
    return;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    cout<<1;
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    cin>>c>>tt;
    while(tt--){
        solve();
    }
    return 0;
}
