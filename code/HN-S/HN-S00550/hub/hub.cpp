#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define N 1001114
int tc,t,n,k,s,dep[N],siz[N],as[N],d[N],trfa[N],op[N],dis[N],a[N],tot,lim,pos,sel[N],ANS;
bool fl=0,del[N];
vector<int>to[N];
void init(int x,int fa){
    dep[x]=dep[fa]+1;siz[x]=1;trfa[x]=fa;
    dis[x]=0;
    for(int y:to[x]){
        if(y==fa)continue;
        init(y,x);siz[x]+=siz[y];
        dis[x]=max(dis[x],dis[y]+1);
    }
}
void dfs2(int x,int fa){
    for(int y:to[x]){
        if(y==fa)continue;
        dfs2(y,x);
    }
    if(dis[x]>=lim){
        if(!fl){fl=1;pos=x;}
    }
}
void _dfs2(int x,int fa){
    d[x]=d[fa]+1;
    for(int y:to[x]){
        if(del[y]||y==fa)continue;
        _dfs2(y,x);
    }
}
bool check2(int mid){
    lim=mid;rep(i,1,n)del[i]=0;pos=0;fl=0;
    dfs2(a[1],0);
    if(!pos){return 1;}
    // d[0]=-1;
    _dfs2(pos,0);
    rep(i,1,n)if((d[i]-1)<=mid)del[i]=1;
    // rep(i,1,n)if(!del[i]){
    //     cout<<((d[i]-1)<=mid)<<'\n';
    //     cout<<"gay "<<i<<' '<<d[i]<<'\n';
    // }
    // rep(i,1,n)cout<<d[i]<<' ';cout<<'\n';
    int pp=1;
    rep(i,1,n)if(!del[i]){pp=i;break;}
    // cout<<pp<<'\n';
    rep(i,1,n)d[i]=1e16;
    _dfs2(pp,0);
    // rep(i,1,n)cout<<d[i]*(bool)(1^del[i])<<' ';cout<<'\n';
    int ppn=0;
    rep(i,1,n)if((!del[i])&&d[i]>d[ppn]){ppn=i;}
    // cout<<ppn<<'\n';
    rep(i,1,n)d[i]=1e16;
    _dfs2(ppn,0);
    int maxn=0;
    rep(i,1,n)if(!del[i])maxn=max(maxn,d[i]);
    return (maxn/2)<=mid;
}
void dfs(int x){
    if(x==n){
        int s=0;
        rep(i,1,n)s+=sel[i];
        if(s!=k)return;
        // rep(i,1,n)cout<<sel[i]<<' ';cout<<'\n';
        queue<int>q;
        rep(i,1,n)d[i]=-1;
        rep(i,1,n)if(sel[i]){q.push(i);d[i]=0;}
        int S=0;
        rep(i,1,n)if(sel[i])for(int y:to[i]){if(sel[y])S++;}
        S/=2;
        if(k-S>2)return;
        while(!q.empty()){
            int x=q.front();q.pop();
            // cout<<x<<' '<<d[x]<<'\n';
            for(int y:to[x]){
                if(d[y]==-1){
                    d[y]=d[x]+1;
                    q.push(y);
                }
            }
        }
        int maxn=0;
        rep(i,1,n)maxn=max(maxn,d[i]);
        // cout<<"mx "<<maxn<<'\n';
        ANS=min(ANS,maxn);
        return;
    }
    sel[x+1]=0;
    dfs(x+1);
    sel[x+1]=1;
    dfs(x+1);
}
void solve(){
    cin>>n>>k;
    rep(i,1,n)to[i].clear();
    rep(i,1,n-1){
        int u,v;cin>>u>>v;
        to[u].push_back(v);to[v].push_back(u);
    }
    if(n<=10){
        ANS=1e16;
        dfs(0);
        cout<<ANS<<'\n';
        return;
    }
    init(1,0);
    int p=0;
    rep(i,1,n)if(dep[i]>dep[p])p=i;
    init(p,0);
    int lst=0;
    rep(i,1,n)if(dep[i]>dep[lst])lst=i;
    int tmp=lst;tot=0;
    while(tmp!=p){a[++tot]=tmp;tmp=trfa[tmp];}
    a[++tot]=p;
    reverse(a+1,a+tot+1);
    init(a[1],0);
    // rep(i,1,tot)cout<<a[i]<<' ';cout<<'\n';
    // cerr<<"ok\n";
    if(k==1){
        cout<<(tot/2)<<'\n';
        return;
    }
    if(k==2){
        int l=0,r=n,ans=n;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check2(mid)){
                ans=mid;r=mid-1;
            }
            else l=mid+1;
        }
        cout<<ans/2<<'\n';
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>tc>>t;while(t--)solve();
}