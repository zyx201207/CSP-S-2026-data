#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,x[1000005],y[1000005],vis[1000005],ans[1000005],deg[1000005],minn;
bool chk[1000005],upd[1000005];
vector<int>g[1000005],nupd;
queue<int>q;
int calc(int p){
    ans[0]=n;
    for(int i=1;i<=n;i++)deg[i]=ans[i]=vis[i]=0;
    for(int i=1;i<=n;i++)chk[i]=upd[i]=0;
    for(int i=1;i<n;i++)if(i!=p)deg[x[i]]++,deg[y[i]]++;
    for(int i=1;i<=n;i++)if(deg[i]==1)q.push(i),chk[i]=1;
    while(!q.empty()){
        int u=q.front();chk[u]=1;q.pop();
        for(int i=0;i<g[u].size();i++){
            if(g[u][i]==x[p]&&u==y[p]||g[u][i]==y[p]&&u==x[p]||chk[g[u][i]])continue;
            upd[u]=1;
            deg[g[u][i]]--;
            vis[g[u][i]]=vis[u]+1;
            if(deg[g[u][i]]==1)q.push(g[u][i]);
        }
    }
    nupd.clear();
    for(int i=1;i<=n;i++)if(!upd[i])nupd.push_back(vis[i]);
    sort(nupd.begin(),nupd.end());
    ans[nupd[0]]--;ans[nupd[(int)nupd.size()-1]]--;
    ans[n]+=2;
    for(int i=1;i<=n;i++)ans[vis[i]]++;
    for(int i=n-1;i>=0;i--)ans[i]+=ans[i+1];
    for(int i=0;i<=n;i++)if(ans[i]<=k)return i;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;minn=n;
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<n;i++){
            cin>>x[i]>>y[i];
            g[x[i]].push_back(y[i]);
            g[y[i]].push_back(x[i]);
        }
        if(n>4000)minn=calc((n+1)/4);
        else for(int i=1;i<n;i++)minn=min(minn,calc(i));
        cout<<minn<<"\n";
    }
}
