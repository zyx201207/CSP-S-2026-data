#include<bits/stdc++.h>
using namespace std;typedef long long ll;
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int main(){//open(migrate3);
    int x,y;cin>>x>>y;
    while(y--){
        int n;ll d;cin>>n>>d;vector<ll>x(n);for(ll&i:x)cin>>i;
        vector<int>dis(n),cnt(n);queue<int>q;int ans=0;
        for(int u=n-1;~u;u--){
            for(int i=0;i<n;i++)cnt[i]=0,dis[i]=114514;vector<int>rec;
            dis[u]=0,cnt[u]=1,q.push(u);while(!q.empty()){
                int u=q.front();q.pop();if(cnt[u]==2)ans++,rec.push_back(u);
                for(int v=u+1;v<n;v++)if(x[v]-x[u]<=d){
                    if(dis[v]>dis[u]+1)dis[v]=dis[u]+1,cnt[v]=cnt[u],q.push(v);
                    else if(dis[v]==dis[u]+1)cnt[v]=min(3,cnt[v]+cnt[u]);
                }
            }for(int v:rec)cerr<<u<<' '<<v<<'\n';
        }cout<<ans<<'\n';
    }
    return 0;
}