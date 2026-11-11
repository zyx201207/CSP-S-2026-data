#include<bits/stdc++.h>
#define gc getchar
#define pb push_back
#define vci vector<int>
#define fr(i,l,r) for(int i=l;i<=r;i++)
#define gr(i,r,l) for(int i=r;i>=l;i--)
#define int long long
using namespace std;
const int N=2e6+10;
inline int read(){
    int x=0;char ch=gc();bool fg=0;
    while(!isdigit(ch)) fg^=ch=='-',ch=gc();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=gc();
    return fg?~(x-1):x;
}
int T,c,n,d,a[N],as[N],nd[N],dp[N];
vci g[N],lt,sz[N];int ans,id[N],iq[N];
int mg(int x,int y){
    int ra=iq[y],la=max(iq[y]-nd[x],0ll);
    return (x?as[x]:0)+(y?sz[id[y]][ra]-(la?sz[id[y]][la-1]:0):0);
}
void dfs(int l,int r){
    fr(x,l,r){
        nd[x]=1e9;
        if(!g[x].size()){
            id[x]=++id[0],sz[id[x]].pb(0),iq[x]=0;
            continue;
        }
        id[x]=id[g[x][0]];
        int tot=g[x].size();
        sz[id[x]].pb(sz[id[x]].back()+tot);
        iq[x]=sz[id[x]].size()-1;
        if(g[x].size()>1) as[x]=mg(g[x][0],g[x][1]);
        else as[x]=as[g[x][0]];
        nd[x]=nd[g[x][0]]+1;
        if(g[x].size()>1) nd[x]=0;
    }
}
void wrk(int l,int r){
    lt.clear(),dfs(l,r);
    int la=0;
    gr(i,r,l){
        if(g[i].size()==1){
            int x=la<lt.size()?lt.back():0;
            ans+=mg(g[i][0],x);
        }
        else if(g[i].empty()){
            int x=la<lt.size()?lt.back():0;
            int y=la+1<lt.size()?lt[lt.size()-2]:0;
            ans+=mg(x,y);
        }
        else ans+=as[i];
        while(g[i].size())
            lt.pb(g[i].back()),g[i].pop_back();
        la++;
    }
}
void cal(int x){
    fr(i,1,x) as[i]=-1; as[x]=0,dp[x]=1;
    int ip=x;
    gr(i,x-1,1){
        while(a[ip]-a[i]>d) ip--;
        if(ip==i) return;
        as[i]=as[ip]+1;
        if(as[ip]!=as[ip-1]) dp[i]=dp[ip];
        else if(as[ip]!=as[ip-2]) dp[i]=dp[ip]+dp[ip-1];
        else dp[i]=3;
        ans+=dp[i]==2?1:0;
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),T=read();
    while(T--){
        n=read(),d=read(),ans=0;
        fr(i,1,n) a[i]=read();
        if(c<=10){
            fr(i,1,n) cal(i);
            printf("%lld\n",ans);
            continue;
        }
        int ip=1,la=1;
        fr(i,1,n){
            while(ip<n&&a[ip+1]-a[i]<=d) ip++;
            if(ip==i) wrk(la,i),la=i+1;
            else g[ip].pb(i);
        }
        fr(i,0,n) as[i]=nd[i]=id[i]=iq[i]=0,g[i].clear(),sz[i].clear();
        printf("%lld\n",ans);
    }
    return 0;
}