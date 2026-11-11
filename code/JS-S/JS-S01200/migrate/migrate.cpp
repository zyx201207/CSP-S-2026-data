#include<bits/stdc++.h>
using namespace std;
void slove(){
    int n,x;
    cin>>n>>x;
    int a[n+2];
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int>g[114514];
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(a[j]-a[i]<=x)g[i].push_back(j);
    int res=0;
    for(int s=1;s<=n;s++){
        vector<int>d(114514,0x3f3f3f3f),cnt(114514),vis(114514);
        priority_queue<pair<int,int>>q;
        q.push({0,s}),d[s]=0,cnt[s]=1,vis[s]=1;
        while(q.size()){
            int u=q.top().second;
            q.pop();
            for(int v:g[u]){
                if(d[v]>=d[u]+1){
                    d[v]=d[u]+1,cnt[v]+=cnt[u];
                    if(!vis[v])vis[v]++,q.push({-d[v],v});
                }
            }
        }
        for(int t=s+1;t<=n;t++)res+=(int)(cnt[t]==2);
    }
    cout<<res<<endl;
    return;
}
main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)slove();
}
