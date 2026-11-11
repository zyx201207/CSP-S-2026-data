#include<bits/stdc++.h>
using namespace std;
int id,T,n,k,rt,mn;
vector<int> e[1000010];
int fdis[1000010],gdis[1000010];
void dfs1(int fa,int x){
    fdis[x]=0;
    for(int v:e[x]){
        if(v==fa) continue;
        dfs1(x,v);
        fdis[x]=max(fdis[x],fdis[v]+1);
    }
}
void dfs2(int fa,int x){
    if(x==1) gdis[x]=-1;
    int tmp=max(gdis[x]+1,fdis[x]);
    if(tmp<mn) mn=tmp,rt=x;
    int mx=0,smx=0;
    for(int v:e[x]){
        if(v==fa) continue;
        if(fdis[v]>=mx) smx=mx,mx=fdis[v];
        else if(fdis[v]>=smx) smx=fdis[v];
    }
    for(int v:e[x]){
        if(v==fa) continue;
        int cur=gdis[x]+1;
        if(fdis[v]==mx) cur=max(cur,smx+1);
        else cur=max(cur,mx+1);
        gdis[v]=cur;
        dfs2(x,v);
    }
}
int h[1000010],hg[1000010];
int dep[1000010],fath[1000010];
void predfs(int fa,int x){
    h[x]=0,dep[x]=dep[fa]+1;
    if(x==rt) dep[x]=0;
    fath[x]=fa;
    for(int v:e[x]){
        if(v==fa) continue;
        predfs(x,v);
        h[x]=max(h[x],h[v]+1);
    }
}
void predfs2(int fa,int x){
    if(x==rt) hg[x]=-1;
    int mx=0,smx=0;
    for(int v:e[x]){
        if(v==fa) continue;
        if(h[v]>=mx) smx=mx,mx=h[v];
        else if(h[v]>=smx) smx=h[v];
    }
    for(int v:e[x]){
        if(v==fa) continue;
        int cur=hg[x]+1;
        if(h[v]==mx) cur=max(cur,smx+1);
        else cur=max(cur,mx+1);
        hg[v]=cur;
        predfs2(x,v);
    }
}
int X,f[1000010],g[1000010],ok[1000010];
void dfs3(int fa,int x){
    f[x]=0;
    for(int v:e[x]){
        if(v==fa) continue;
        dfs3(x,v);
        f[x]+=f[v];
    }
    if(f[x]||h[x]>=X) f[x]++;
}
void dfs4(int fa,int x){
    if(x==rt) g[x]=0;
    int sum=g[x];
    for(int v:e[x]){
        if(v==fa) continue;
        sum+=f[v];
    }
    for(int v:e[x]){
        if(v==fa) continue;
        int cur=sum-f[v];
        if(cur||hg[v]>=X) cur++;
        g[v]=cur;
        dfs4(x,v);
    }
}
struct SOL{
    int h[1000010],hg[1000010];
void predfs(int fa,int x){
    h[x]=0;
    for(int v:e[x]){
        if(v==fa) continue;
        predfs(x,v);
        h[x]=max(h[x],h[v]+1);
    }
}
void predfs2(int fa,int x){
    if(x==rt) hg[x]=-1;
    int mx=0,smx=0;
    for(int v:e[x]){
        if(v==fa) continue;
        if(h[v]>=mx) smx=mx,mx=h[v];
        else if(h[v]>=smx) smx=h[v];
    }
    for(int v:e[x]){
        if(v==fa) continue;
        int cur=hg[x]+1;
        if(h[v]==mx) cur=max(cur,smx+1);
        else cur=max(cur,mx+1);
        hg[v]=cur;
        predfs2(x,v);
    }
}
}S[2];
vector<int> son;
#define pii pair<int,int>
#define fr first
#define sc second
vector<pii> hv[2];
void getmn(int fa,int x,int id){
    hv[id].push_back({dep[x],f[x]});
    for(int v:e[x])if(v!=fa) getmn(x,v,id);
}
int OKK=0;
void solve(int fa,int x){
    if(x!=rt){
    int cur=f[x];
    int dis=0,p=x,mx=0,lst=x,flg=0;
    while(1){
        p=fath[p];
        dis++,mx=max(mx,dis);
        for(int v:e[p]){
            if(v==fath[p]||v==lst) continue;
            mx=max(mx,dis+h[v]+1);
        }
        if(dis>X) flg=1,dis=0;

        lst=p;
    }}
    for(int v:e[x]){
        if(v==fa) continue;
        solve(x,v);
    }
}
bool chk(int x){
    X=x;
    dfs3(0,rt),dfs4(0,rt);
    if(f[rt]<=k) return 1;
    hv[0].clear(),hv[1].clear();
    getmn(rt,son[0],0),getmn(rt,son[1],1);
    OKK=0;
    solve(0,rt);
    if(OKK) return 1;
    int o=0;
    if(son.size()>=3) o=h[son[2]]+1;
    for(pii a:hv[0])for(pii b:hv[1]){
        if(min(a.fr,b.fr)+o>X) continue;
        // if(a.fr+b.fr)
    }
    return 0;
}
int cal(int a,int b){
    return (a-b+1)/2;
}
int key[1000010],vis[1000010];
void dfs(int fa,int x){
    if(!key[x]) return;
    vis[x]=1;
    for(int v:e[x])if(!vis[v]) dfs(x,v);
}
int dis[1000010];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>id>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1,x,y;i<n;i++){
            cin>>x>>y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        if(k==n){
            cout<<0<<'\n';
            continue;
        }
        if(id==13||id==14){
            int m=n/2;
            if(k>=m){
                cout<<1<<'\n';
            }else{
                int s=m/2,tmp=k/2;
                cout<<max(cal(s,tmp),cal(m-s,k-tmp))+1<<'\n';
            }
            continue;
        }
        if(n<=10){
        int ans=1e9;
        for(int i=0;i<(1<<n);i++){
            if(__builtin_popcount(i)!=k) continue;
            for(int j=1;j<=n;j++){
                if(i&(1<<j-1)) key[j]=1;
                else key[j]=0;
            }
            for(int j=1;j<=n;j++) vis[j]=0;
            int cnt=0;
            for(int j=1;j<=n;j++){
                if(!vis[j]&&key[j]) dfs(0,j),cnt++;
            }
            if(cnt>2) continue;
            for(int j=1;j<=n;j++) vis[j]=0,dis[j]=1e9;
            queue<int> q;
            for(int j=1;j<=n;j++)if(key[j]) q.push(j),dis[j]=0,vis[j]=1;
            while(!q.empty()){
                int u=q.front(); q.pop();
                for(int v:e[u]){
                    if(!vis[v]){
                        dis[v]=dis[u]+1,vis[v]=1;
                        q.push(v);
                    }
                }
            }
            int mx=0;
            for(int j=1;j<=n;j++) mx=max(mx,dis[j]);
            ans=min(ans,mx);
            if(cnt>2) continue;
        }
        cout<<ans<<'\n';
        continue;
        }

        // mn=1e9;
        // dfs1(0,1),dfs2(0,1);
        // predfs(0,rt),predfs2(0,rt);
        // son.clear();
        // for(int v:e[rt]) son.push_back(v);
        // sort(son.begin(),son.end(),[](int u,int v){return h[u]>h[v];});
        // S[0].predfs(rt,son[0]),S[0].predfs2(rt,son[0]);
        // S[1].predfs(rt,son[1]),S[1].predfs2(rt,son[1]);
        // int l=0,r=n-1;
        // while(l<r){
        //     int mid=l+r>>1;
        //     if(chk(mid)) r=mid;
        //     else l=mid+1;
        // }
        // cout<<r<<'\n';
    }
    return 0;
}