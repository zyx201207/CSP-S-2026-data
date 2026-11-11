
#include<bits/stdc++.h>
#define ll long long

using namespace std;
int c,T,n;
ll d[5010],a[5010],vis[5010],f[5010],cnt,dd;
struct node{
    int x,w;
};
void bfs(int s){
    queue<node> q;
    q.push({s,0});
    for(int i=1;i<=n;i++){
        d[i]=1e18;
        vis[i]=0;
        f[i]=0;
    }
    f[s]=1;
    d[s]=0;
    while(q.size()){
        node u=q.front();
        q.pop();
        if(vis[u.x])continue;
        vis[u.x]=1;
        for(int i=1;i<=n;i++){
            if(i!=u.x&&abs(a[i]-a[u.x]<=dd)){
                if(d[i]>=d[u.x]+1){
                    d[i]=d[u.x]+1;
                    if(d[i]==d[u.x]+1)f[i]+=f[u.x];
                    else{
                        f[i]=f[u.x];
                        q.push({i,d[i]});
                    }
                }
            }
        }
    }
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>dd;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){
            bfs(i);
            for(int j=i+1;j<=n;j++)if(f[j]==2)cnt++;
        }
        cout<<cnt<<'\n';
        cnt=0;
    }
    return 0;
}
//Oct31==Dec25?
