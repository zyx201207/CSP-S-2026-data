#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k,dis[N],id,pre[N],mxd[N],mxd2[N],pa[N],tot;
bool vis[N];
vector<int> G[N],cnt[N];
void dfs(int u,int fa){
    if(!id||dis[u]>dis[id]) id=u;
    for(auto v:G[u]){
        if(v==fa) continue;
        pre[v]=u;
        dis[v]=dis[u]+1;
        dfs(v,u);
    }
}
vector<int> vc;
void dfs2(int u,int fa,int rt,int d){
    mxd[rt]=max(mxd[rt],d);
    mxd2[u]=0;
    for(auto v:G[u]){
        if(v==fa||vis[v]) continue;
        dfs2(v,u,rt,d+1);
        mxd2[u]=max(mxd2[u],mxd2[v]+1);
    }
    if(u!=pa[rt]) vc.push_back(mxd2[u]);
}
int q[N],ql,qr,val[N];
bool check(int x){
    int must=0;
    for(int i=x+1;i<=tot-x;i++)
        if(x<mxd[i]) must+=cnt[i][x];
    if(must>k) return 0;
    for(int i=x+1;i<=tot;i++) val[i]=mxd[i]-i;
    int j=x+2;
    ql=1,qr=0;
    for(int i=x+1;i<=tot;i++){
        j=max(j,i+1);
        while(j<=tot){
            if(mxd[j]+1>x) break;
            if(j-i>1&&mxd[(i+j)/2]+(i+j)/2-i>x) break;
            while(ql<=qr&&q[ql]<=(i+j+1)/2) ql++;
            if(ql<=qr&&val[q[ql]]+j+1>x) break;
            while(ql<=qr&&val[j]>=val[q[qr]]) qr--;
            q[++qr]=j;
            j++;
        }
        int res=i-x+must;
        if(j<=tot) res+=max(1,tot-x-j+1);
        if(res<=k) return 1;
    }
    return 0;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) G[i].clear(),vis[i]=0;
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(n==k){
        cout<<"0\n";
        return;
    }
    dis[1]=id=0;dfs(1,0);int s=id;
    dis[s]=id=0;dfs(s,0);int t=id;
    tot=0;
    for(int i=t;;i=pre[i]){
        pa[++tot]=i;vis[i]=1;
        if(i==s) break;
    }
    for(int i=1;i<=tot;i++){
        mxd[i]=0;
        vc.clear();
        dfs2(pa[i],0,i,0);
        cnt[i].clear();
        cnt[i].resize(mxd[i]);
        for(auto v:vc) cnt[i][v]++;
        for(int j=mxd[i]-2;j>=1;j--)
            cnt[i][j]+=cnt[i][j+1];
    }
    int l=1,r=tot/2;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<'\n';
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int cid,T;cin>>cid>>T;
    while(T--) solve();
    return 0;
}