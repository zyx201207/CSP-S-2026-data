#include<bits/stdc++.h>
using namespace std;
bool MED;
template<typename T>inline void read(T &x){
  x=0;char c=getchar();int f=0;
  while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
  while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
  if(f)x=~x+1;
}

#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define pb push_back
#define eb emplace_back
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define fi first
#define se second
#define SZ(x) ((int)((x).size()))
#define all(x) (x).begin(),(x).end()

template<typename T,typename U>inline void cmin(T &x,U y){if(y<x)x=y;}
template<typename T,typename U>inline void cmax(T &x,U y){if(y>x)x=y;}

const int N=2e6+5;

int cnt,head[N],nxt[N],to[N];
inline void adde(int u,int v){
  nxt[++cnt]=head[u];
  to[cnt]=v,head[u]=cnt;
}

int sub,T;

int n,k;

namespace solve1{
  int res;
  int ans[N],x[N],y[N];
  
  int stk[N],top,siz[N],rt;
  
  int maxn,r;
  void dfs1(int u,int fa,int d){
    if(d>maxn)maxn=d,r=u;
    for(int i=head[u];i;i=nxt[i]){
      int v=to[i];if(v==fa||v==rt)continue;
      dfs1(v,u,d+1);
    }
  }
  int dfs2(int u,int fa,int ed){
    stk[++top]=u;
    if(u==ed)return 1;
    for(int i=head[u];i;i=nxt[i]){
      int v=to[i];if(v==fa||v==rt)continue;
      
      if(dfs2(v,u,ed))return 1;
    }
    --top;
    return 0;
  }
  
  int dep[N],maxd[N],del[N];
  
  void dfs3(int u,int fa,int d){
    siz[u]=1,dep[u]=d,maxd[u]=d,del[u]=0;
    for(int i=head[u];i;i=nxt[i]){
      int v=to[i];if(v==fa||v==rt)continue;
      dfs3(v,u,d+1),siz[u]+=siz[v],cmax(maxd[u],maxd[v]);
    }
  }
  
  int cc(int u,int v){
    
//    printf("cc %d %d\n",u,v);
    
    rt=v;
    
    maxn=0,r=u,dfs1(u,0,0);
    int p1=r;
    maxn=0,r=p1,dfs1(p1,0,0);
    int p2=r;
    
    top=0,dfs2(p1,0,p2);
    
    int p=stk[(top+1)/2];
    dfs3(p,0,0);
    
//    printf("p : %d (%d,%d)\n",p,p1,p2);
    
    priority_queue<PII> q;
    q.push({maxd[p],p});
    int cur=0;
    while(!q.empty()){
      PII o=q.top();q.pop();
      
      int u=o.se;
      ans[++cur]=o.fi,del[u]=1;
      
      if(!q.empty())cmax(ans[cur],q.top().fi+1);
      
//      printf("del %d %d\n",u,ans[cur]);
      
      for(int i=head[u];i;i=nxt[i]){
        int v=to[i];if(del[v]||v==rt)continue;
        q.push({maxd[v]-dep[v],v});
      }
    }
    
    return siz[p];
  }
  
  void calc(int u,int v){
    
//    printf("----------------\ncalc (%d,%d)\n",u,v);
    
    int su=cc(u,v);
    for(int i=1;i<=su;++i)x[i]=ans[i];
    
//    printf("su : %d\n",su);
//    for(int i=1;i<=su;++i)printf("%d ",x[i]);
//    printf("\n");
    
    int sv=cc(v,u);
    for(int i=1;i<=sv;++i)y[i]=ans[i];
    
//    printf("sv : %d\n",sv);
//    for(int i=1;i<=sv;++i)printf("%d ",y[i]);
//    printf("\n");
    
    for(int i=1;i<=su;++i)if(k-i>=1&&k-i<=sv)
      cmin(res,max(x[i],y[k-i]));
      
//    printf("res : %d\n",res);
  }
  
  void dfs(int u,int fa){
    for(int i=head[u];i;i=nxt[i]){
      int v=to[i];if(v==fa)continue;
      calc(u,v);
      dfs(v,u);
    }
  }
  
  void main(){
    
    res=n;
    dfs(1,0);
    printf("%d\n",res);
    
    return;
  }
}

namespace solve2{
  
  void main(){
    
    int m=n/2;
    
    if(k>=n){
      printf("0\n");
      return;
    }
    
    if(k>=m){
      printf("1\n");
      return;
    }
    
    int l=1,r=m,ans=m;
    while(l<=r){
      int x=(l+r)>>1;
      
      int pl=x,pr=m-x+1;
      if(pl>=pr||k>=pr-pl+1)ans=x,r=x-1;
      else{
        int px=k/2,py=k-px;
        int cl=pl+px-1,cr=pr-py+1;
        
        int fl=1;
        for(int i=cl+1;i<cr;++i)
          fl&=min(i-cl+1,cr-i+1)<=x;
        if(fl)ans=x,r=x-1;
        else l=x+1;
      }
    }
    
    printf("%d\n",ans);
    
    return;
  }
}

namespace solve3{
  int fa[N],siz[N],son[N],dep[N],top[N],dfn[N],id[N],tot;
  
  void dfs1(int u,int f){
    fa[u]=f,siz[u]=1,son[u]=0,dep[u]=dep[f]+1;
    for(int i=head[u];i;i=nxt[i]){
      int v=to[i];if(v==f)continue;
      dfs1(v,u),siz[u]+=siz[v];
      if(son[u]==0||siz[v]>siz[son[u]])son[u]=v;
    }
  }
  void dfs2(int u,int t){
    top[u]=t,dfn[u]=++tot,id[tot]=u;
    if(son[u]==0)return;
    dfs2(son[u],t);
    for(int i=head[u];i;i=nxt[i]){
      int v=to[i];if(v==fa[u]||v==son[u])continue;
      dfs2(v,v);
    }
  }
  inline int lca(int u,int v){
    while(top[u]!=top[v]){
      if(dep[top[u]]<dep[top[v]])swap(u,v);
      u=fa[top[u]];
    }
    if(dep[u]<dep[v])swap(u,v);
    return v;
  }
  inline int dis(int u,int v){
    int l=lca(u,v);
    return dep[u]+dep[v]-2*dep[l];
  }
  
  struct node{
    int x,y;
  };
  
  inline node operator+(const node&x,const node&y){
    node r=x;
    if(dis(y.x,y.y)>dis(r.x,r.y))r=y;
    if(dis(x.x,y.x)>dis(r.x,r.y))r={x.x,y.x};
    if(dis(x.x,y.y)>dis(r.x,r.y))r={x.x,y.y};
    if(dis(x.y,y.x)>dis(r.x,r.y))r={x.y,y.x};
    if(dis(x.y,y.y)>dis(r.x,r.y))r={x.y,y.y};
    return r;
  }
  
  node dat[N<<2];
  #define ls (p<<1)
  #define rs (p<<1|1)
  inline void pushup(int p){
    dat[p]=dat[ls]+dat[rs];
  }
  void build(int p,int l,int r){
    if(l==r){
      dat[p]={id[l],id[r]};
      return;
    }
    int mid=(l+r)>>1;
    build(ls,l,mid),build(rs,mid+1,r);
    pushup(p);
  }
  node qy(int p,int l,int r,int L,int R){
    if(L<=l&&r<=R)return dat[p];
    int mid=(l+r)>>1;
    if(L<=mid&&mid<R)return qy(ls,l,mid,L,R)+qy(rs,mid+1,r,L,R);
    if(L<=mid)return qy(ls,l,mid,L,R);
    return qy(rs,mid+1,r,L,R);
  }
  #undef ls
  #undef rs
  
  int res;
  
  void dfs3(int u,int f){
    for(int i=head[u];i;i=nxt[i]){
      int v=to[i];if(v==f)continue;
      dfs3(v,u);
      
      node pv=qy(1,1,n,dfn[v],dfn[v]+siz[v]-1);
      
      
      node pu;
      if(dfn[v]!=1&&dfn[v]+siz[v]-1!=n)
        pu=qy(1,1,n,1,dfn[v]-1)+qy(1,1,n,dfn[v]+siz[v],n);
      else if(dfn[v]!=1)
        pu=qy(1,1,n,1,dfn[v]-1);
      else
        pu=qy(1,1,n,dfn[v]+siz[v],n);
        
        
      cmin(res, max((dis(pu.x,pu.y)+1)/2, (dis(pv.x,pv.y)+1)/2) );
    }
  }
  
  void main(){
    
    tot=0;
    dfs1(1,0),dfs2(1,1);
    
    
    build(1,1,n);
    
    int res=n;
    dfs3(1,0);
    
    printf("%d\n",res);
    
    return;
  }
}

void solve(){
  read(n),read(k);
  
  for(int i=1;i<=n;++i)head[i]=0;
  cnt=0;
  
  for(int i=1;i<n;++i){
    int u,v;read(u),read(v);
    adde(u,v),adde(v,u);
  }
  
  if(sub<=10)solve1::main();
  if(sub==13||sub==14)solve2::main();
  if(sub==11||sub==12)solve3::main();
}

bool MST;
int main(){
  fprintf(stderr,"%.3lf MB\n",(&MED-&MST)/1048576.0);
  
//  freopen("hub4.in","r",stdin);
  
  freopen("hub.in","r",stdin);
  freopen("hub.out","w",stdout);
  
  read(sub),read(T);while(T--)solve();
  
  return 0;
}
