#include<bits/stdc++.h>
using namespace std;
#define N 5010
int c,n,vis[N],dis[N][N][3];
long long x[2000010],d;
int l[2000010],r[2000010];
vector<int>g[N];
struct qwq{int u,w,v;};
void bfs(int s){
    queue<qwq>q;
    q.push({s,0,3});
    for(int i=1;i<=n;i++)vis[i]=0;
    vis[s]=3;
    while(!q.empty()){
        qwq u=q.front();
        q.pop();
        dis[s][u.u][u.v-1]=u.w;
        for(int v:g[u.u]){
            vis[v]++;
            if(vis[v]<=3)q.push({v,u.w+1,vis[v]});
        }
    }
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i];
    if(n==1){cout<<0<<'\n';return;}
    if(c==11||c==12){
        long long cnt=d/(x[2]-x[1]);
        if(cnt<=1)cout<<0<<'\n';
        else cout<<max(0ll,n-2*cnt+1)<<'\n';
        return;
    }
    if(c==0||c==13||c==14){
        for(int i=1;i<=n;i++){
            int L=i,R=n;
            while(L<=R){
                int mid=(L+R)>>1;
                if(x[mid]-x[i]<=d)L=mid+1,r[i]=mid;
                else R=mid-1;
            }
            L=1,R=i;
            while(L<=R){
                int mid=(L+R)>>1;
                if(x[i]-x[mid]<=d)R=mid-1,l[i]=mid;
                else L=mid+1;
            }
        }
        for(int i=2;i<n;i++)
            if(l[i]==1&&r[i]==n){
                int l0,l1,r0,r1;l0=l1=r0=r1=0;
                for(int j=1;j<i;j++)
                    if(r[j]==i+1)l1++;
                    else if(r[j]==i)l0++;
                for(int j=1;j<i;j++)
                    if(l[j]==i-1)r1++;
                    else if(l[j]==i)r0++;
                cout<<(long long)(l1*r0+r1*l0)<<'\n';
                return;
            }
        cout<<0<<'\n';
        return;
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n&&x[j]-x[i]<=d;j++)
            g[i].push_back(j),g[j].push_back(i);
    for(int i=1;i<=n;i++)bfs(i);
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(dis[i][j][0]&&dis[i][j][0]==dis[i][j][1]&&dis[i][j][1]!=dis[i][j][2])
                ans++;
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)dis[i][j][0]=dis[i][j][1]=dis[i][j][2]=0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;cin>>c>>t;while(t--)solve();
    return 0;
}
