#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[500005];

vector<pair<int,int> > t[500505];

int u,v;
bool vis[500505];
int ans=0;
void dfs(int i,int tim){
    if(i==v){
        ans=min(ans,tim);
        cout<<tim<<'\n';
        return;
    }

    for(auto j:t[i]){
        if(vis[j.first])continue;
        vis[j.first]=true;
        dfs(j.first,tim+j.second);
        vis[j.first]=false;
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int aa,tt;
            cin>>aa>>tt;

            t[m+i].push_back({aa,tt});
            t[aa].push_back({m+i,tt});
        }
    }

    while(q--){
        cin>>u>>v;
        for(int i=1;i<=n+m;i++)vis[i]=false;
        ans=INT_MAX;
        dfs(u,0);
        cout<<ans+w[u]+w[v]<<'\n';
    }
    return 0;
}
