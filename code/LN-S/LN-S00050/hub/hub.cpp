#include<bits/stdc++.h>
using namespace std;
vector<int> a[2000005];
int v[2000005];
int s[2000005];
bool vis[2000005];
void dfs(int n,int dep){
    if(dep==k){
        memset(vis,0,sizeof(vis));
        df(1);
        bool f=0;
        for(int i=1;i<=k;i++){
            if(!f&&!vis[i])}
            df(i);
            f=1;
        }
        bool fl=0;
        for(int i=1;i<=k;i++){
            if(!vis[i]){
                fl=1;
                break;
            }
        }
        if(fl){

        }
    }
    for(int i=1;i<=n;i++){
        if(!v[i]){
            s[dep+1]=i;
            dfs(n,dep+1);
        }
    }
}
void df(int now){
    for(int i=0;i<a[now].size();i++){
        vis[a[now][i]]=1;
        df(a[now][i]);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,k;
        cin>>n>>k;
        for(int j=1;j<n;j++){
            int u,v;
            cin>>u>>v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        cout<<0<<'\n';
    }
    return 0;
}
