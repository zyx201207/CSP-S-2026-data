#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int c,t,n,k,u,v,ans,d[1000010],dis[1000010];
bool vis[1000010],a[1000010];
vector<int> g[1000010];
bool check(int x){
    int cnt=0,cnt1=0;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    memset(a,0,sizeof(a));
    priority_queue<pii,vector<pii>,greater<pii> > q;
    for(int i=1;i<=n;i++)if(d[i]==1){q.push(make_pair(0,i));dis[i]=0;}
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        vis[u]=1;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(vis[v])continue;
            d[v]--;
            dis[v]=min(dis[v],dis[u]+1);
            if(dis[v]>=x){
                a[v]=1;
                cnt++;
                dis[v]=-1;
                bool bbb=0;
                for(int j=0;j<g[v].size();j++)if(a[g[v][j]])bbb=1;
                if(!bbb)cnt1++;
            }
            if(d[v]==1)q.push(make_pair(dis[v],v));
        }
    }
    return cnt<=k&&cnt1<=2;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(g,0,sizeof(g));
        memset(d,0,sizeof(d));
        cin>>n>>k;
        if(k>=n){cout<<0<<'\n';continue;}
        for(int i=1;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            d[u]++;
            d[v]++;
        }
        int l=1,r=n-1,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(check(mid)){ans=mid;r=mid-1;}
            else l=mid+1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
