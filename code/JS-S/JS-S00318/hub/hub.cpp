#include<bits/stdc++.h>
using namespace std;

int c,t,n,k,vis[200005],vis2[200005],dis[200005],ans;
vector <int> v[200005];

void dfs2(int x,int s){
    vis2[x]=s;
    for(int i:v[x]){
        if(!vis2[i] && vis[i]) {
            dfs2(i,s);
        }
    }
}

void dfs3(int x){
    for(int i:v[x]){
        if(dis[i]>dis[x]+1){
            dis[i]=dis[x]+1;
            dfs3(i);
        }
    }
}

void check(){
    int cnt=0,ss=0;
    for(int i=1;i<=n;i++){
        vis2[i]=0;
    }
    for(int i=1;i<=n;i++){
        if(vis[i] && !vis2[i]){
            dfs2(i,++cnt);
        }
    }
    //cout<<cnt;
    if(cnt>2) return;

    for(int i=1;i<=n;i++){
        dis[i]=999999999;
        if(vis[i]==1) dis[i]=0;
    }
    for(int i=1;i<=n;i++){
        dfs3(i);
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        sum=max(sum,dis[i]);
    }
    ans=min(ans,sum);
}
void dfs(int x,int a){
    if(x==k+1) {
        check();
        return;
    }
    for(int i=a;i<=n;i++){
        vis[i]=1;
        dfs(x+1,i+1);
        vis[i]=0;
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=999999999;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v1;
            cin>>u>>v1;
            v[u].push_back(v1);
            v[v1].push_back(u);
        }
        dfs(1,1);
        cout<<ans<<endl;
        for(int i=1;i<=n;i++){
            v[i].clear();
        }
    }
}
