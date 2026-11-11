#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+7,maxm=505,inf=1e18+7;
int c,n,m,d,q,x,y,ans,w[maxn],k[maxn],dis[maxm][maxn];
bool flag=true;
vector<int> a[maxn],t[maxn];
int chk(int fr,int p)
{
    int l=1,r=k[fr],mid=(l+r)>>1;
    while(l<r){
        if(a[fr][mid]==p){
            return mid;
        }
        else if(a[fr][mid]<p){
            l=mid+1;
        }
        else{
            r=mid;
        }
        mid=(l+r)>>1;
    }
    if(a[fr][mid]!=p){
        return -1;
    }
    return mid;
}
void dfs(int sub,int p,int ts,int num)
{
    if(num>=dis[sub][p]){
        return;
    }
    num+=t[sub][ts];
    dis[sub][p]=num;
    if(p==y) ans=min(ans,dis[sub][p]);
    for(int i=1;i<=k[sub];i++){
        dis[sub][a[sub][i]]=min(dis[sub][a[sub][i]],num+t[sub][i]);
        if(a[sub][i]==y) ans=min(ans,dis[sub][a[sub][i]]);
        for(int j=1;j<=n;j++){
            if(j==sub) continue;
            int res=chk(j,a[sub][i]);
            if(res!=-1){
                dfs(j,a[j][res],res,num+t[sub][i]);
            }
        }
    }
}
vector<pair<int,int> > mp[maxn];
int ds[maxn];
bool vis[maxn];
void bfs(int s)
{
    for(int i=1;i<=m;i++){
        ds[i]=inf;
    }
    ds[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i=0;i<mp[t].size();i++){
            int v=mp[t][i].first;
            if(ds[t]+mp[t][v].second<ds[v]){
                ds[v]=ds[t]+mp[t][v].second;
                q.push(v);
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        a[i].push_back(0);
        t[i].push_back(0);
        if(k[i]>2) flag=false;
        for(int j=1;j<=k[i];j++){
            scanf("%lld %lld",&x,&y);
            a[i].push_back(x);
            t[i].push_back(y);
        }
    }
    while(q--){
        scanf("%lld %lld",&x,&y);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dis[i][j]=inf;
            }
        }
        ans=inf;
        for(int i=1;i<=n;i++){
            int res=chk(i,x);
            if(res!=-1){
                dfs(i,x,res,w[x]);
            }
        }
        printf("%lld\n",ans+w[y]);
    }
    return 0;
}
