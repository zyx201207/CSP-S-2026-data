#include<bits/stdc++.h>
using namespace std;
#define N 1000005
vector<int>T[N];
int cid,Tc,n,k;
int dis[N],from[N];
int dfn[N],pa[N],tot,dept[N];
int st[20][N];
int gmn(int x,int y){
    return dfn[x]<dfn[y]?x:y;
}
void dfs0(int x,int fa){
    dfn[x]=++tot;
    dept[x]=dept[fa]+1;
    pa[x]=fa;
    st[0][dfn[x]]=pa[x];
    for(int v:T[x])if(v!=fa)dfs0(v,x);
}
int lca(int x,int y){
    if(x==y)return x;
    x=dfn[x],y=dfn[y];
    if(x>y)swap(x,y);
    int d=__lg(y-x);
    return gmn(st[d][x+1],st[d][y-(1<<d)+1]);
}
int dist(int x,int y){
    int LCA=lca(x,y);
    return dept[x]+dept[y]-dept[LCA]*2;
}
void dfs1(int x){
    for(int v:T[x])if(dis[v]==-1){
        dis[v]=dis[x]+1;
        from[v]=x;
        dfs1(v);
    }
}
int getcenter(int x,int b){
    memset(dis,-1,sizeof(dis));
    dis[x]=dis[b]=0;
    dfs1(x);
    int S=1;
    for(int i=1;i<=n;i++)if(dis[i]>dis[S])S=i;
    memset(dis,-1,sizeof(dis));
    dis[S]=dis[b]=0;
    dfs1(S);
    int T=1;
    for(int i=1;i<=n;i++)if(dis[i]>dis[T])T=i;
    int cd=dis[T]/2;
    while(cd--)T=from[T];
    return T;
}
int diam[N],dl;
int dep[N],h[N],bl[N];
int distd(int x,int y){
    // assert bl[x]!=bl[y]
    return dep[x]+dep[y]+abs(bl[x]-bl[y]);
}
struct Diam{
    int s,t,len;
    Diam(){}
    Diam(int s,int t,int len):s(s),t(t),len(len){}
    bool operator<(const Diam &o)const{
        return len<o.len;
    }
    Diam operator+(const Diam &o)const{
        Diam tmp(0,0,0);
        if(tmp<Diam(s,t,len))tmp=Diam(s,t,len);
        if(tmp<Diam(o.s,o.t,o.len))tmp=Diam(o.s,o.t,o.len);
        if(tmp<Diam(s,o.t,dist(s,o.t)))tmp=Diam(s,o.t,dist(s,o.t));
        if(tmp<Diam(o.s,t,dist(o.s,t)))tmp=Diam(o.s,t,dist(o.s,t));
        if(tmp<Diam(s,o.s,dist(s,o.s)))tmp=Diam(s,o.s,dist(s,o.s));
        if(tmp<Diam(t,o.t,dist(t,o.t)))tmp=Diam(t,o.t,dist(t,o.t));
        return tmp;
    }
}fd[N],pred[N],sufd[N];
void dfs2(int x,int b1,int b2,int fa,int id){
    dep[x]=dep[fa]+1;
    bl[x]=id;
    fd[x]=Diam(x,x,0);
    h[x]=0;
    for(int v:T[x])if(v!=fa && v!=b1 && v!=b2){
        dfs2(v,b1,b2,x,id);
        h[x]=max(h[x],h[v]+1);
        fd[x]=fd[x]+fd[v];
    }
}

int prec[N],sufc[N];
int dd[N],ht[N];
void dfs3(int x,int fa){
    ht[x]=0;
    from[x]=fa;
    for(int v:T[x])if(v!=fa){
        dfs3(v,x);
        ht[x]=max(ht[x],ht[v]+1);
    }
}
void dfs4(int x,int b1,int b2,int fa){
    dep[x]=dep[fa]+1;
    h[x]=0;
    for(int v:T[x])if(v!=fa && v!=b1 && v!=b2){
        dfs4(v,b1,b2,x);
        h[x]=max(h[x],h[v]+1);
    }
}
int fdiam[N],lf;
void init(){
    tot=0,dl=0;
    for(int i=1;i<=n;i++)T[i].clear();
    memset(bl,0,sizeof(bl));
    memset(diam,0,sizeof(diam));
    memset(st,0,sizeof(st));
    memset(pa,0,sizeof(pa));
    memset(dept,0,sizeof(dept));
    memset(prec,0,sizeof(prec));
    memset(sufc,0,sizeof(sufc));
    memset(fdiam,0,sizeof(fdiam));
    lf=0;
    memset(dd,0,sizeof(dd));
    memset(ht,0,sizeof(ht));
    memset(fd,0,sizeof(fd));
    memset(pred,0,sizeof(pred));
    memset(sufd,0,sizeof(sufd));
}
void getpre(int d){
    // printf("getpre %d\n",d);
    int pc;
    for(int i=1;i<=n;i++)if(pred[i].len>d*2){
        pc=i;
        break;
    }
    int rt=getcenter(diam[pc],diam[pc+1]);
    // printf("pc=%d, rt=%d\n",pc,rt);
    dfs3(rt,0);
    lf=0;
    int tmp=diam[dl];
    fdiam[++lf]=tmp;
    while(tmp!=rt){
        tmp=from[tmp];
        fdiam[++lf]=tmp;
    }
    fdiam[0]=fdiam[lf+1]=0;
    for(int i=1;i<=lf;i++)dfs4(fdiam[i],fdiam[i-1],fdiam[i+1],0);
    for(int i=1;i<=n;i++)dd[i]=n+1;
    for(int i=1;i<=n;i++)if(dep[i]>0 && h[i]>=d)dd[i]=bl[i];
    for(int i=1;i<=lf;i++){
        int u=fdiam[i];
        if(i>1)dd[u]=min(dd[u],dd[fdiam[i-1]]);
        int v=max(i,i+d-h[u]);
        if(v<=lf)dd[fdiam[v]]=min(dd[fdiam[v]],bl[u]);
    }
    for(int i=0;i<=n;i++)prec[i]=0;
    // for(int i=1;i<=n;i++)printf("%d ",dd[i]);
    // printf("\n");
    for(int i=1;i<=n;i++)prec[dd[i]]++;
    for(int i=1;i<=n;i++)prec[i]+=prec[i-1];
    for(int i=1;i<=dl;i++)prec[i]=max(1,prec[i]);
    for(int i=1;i<pc;i++)prec[i]=1;
    // for(int i=1;i<=dl;i++)printf("%d ",prec[i]);
    // printf("\n");
}
void getsuf(int d){
    // printf("getsuf %d\n",d);
    int pc;
    for(int i=n;i>=1;i--)if(sufd[i].len>d*2){
        pc=i;
        break;
    }
    int rt=getcenter(diam[pc],diam[pc-1]);
    // printf("pc=%d, rt=%d\n",pc,rt);
    dfs3(rt,0);
    lf=0;
    int tmp=diam[1];
    fdiam[++lf]=tmp;
    while(tmp!=rt){
        tmp=from[tmp];
        fdiam[++lf]=tmp;
    }
    fdiam[0]=fdiam[lf+1]=0;
    // for(int i=1;i<=lf;i++)printf("(%d ",fdiam[i]);
    // printf("\n");
    for(int i=1;i<=lf;i++)dfs4(fdiam[i],fdiam[i-1],fdiam[i+1],0);
    for(int i=1;i<=n;i++)dd[i]=0;
    // printf("** %d %d\n",dep[3],h[3]);
    for(int i=1;i<=n;i++)if(dep[i]>0 && h[i]>=d){
        dd[i]=bl[i];
        // printf("* %d\n",i);
    }
    for(int i=1;i<=lf;i++){
        int u=fdiam[i];
        // printf("u=%d\n",u);
        if(i>1)dd[u]=max(dd[u],dd[fdiam[i-1]]);
        int v=max(i,i+d-h[u]);
        if(v<=lf)dd[fdiam[v]]=max(dd[fdiam[v]],bl[fdiam[i]]);
    }
    for(int i=1;i<=n;i++)sufc[i]=0;
    for(int i=1;i<=n;i++)sufc[dd[i]]++;
    // for(int i=1;i<=n;i++)printf("%d ",dd[i]);
    // printf("\n");
    for(int i=dl;i>=1;i--)sufc[i]+=sufc[i+1];
    for(int i=1;i<=dl;i++)sufc[i]=max(sufc[i],1);
    for(int i=dl;i>pc;i--)sufc[i]=1;
    // for(int i=1;i<=dl;i++)printf("%d ",sufc[i]);
    // printf("\n");
}
bool check(int d){
    if(d*2>=dl)return true;
    getpre(d),getsuf(d);
    for(int i=1;i<dl;i++)if(prec[i]+sufc[i+1]<=k)return true;
    return false;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>cid>>Tc;
    while(Tc--){
        cin>>n>>k;
        init();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            T[v].push_back(u);
            T[u].push_back(v);
        }
        dfs0(1,0);
        for(int j=1;j<20;j++)for(int i=1;i+(1<<j)-1<=n;i++)st[j][i]=gmn(st[j-1][i],st[j-1][i+(1<<j-1)]);
        // get diameter
        memset(dis,-1,sizeof(dis));
        dis[1]=0;
        dfs1(1);
        int S=1;
        for(int i=1;i<=n;i++)if(dis[i]>dis[S])S=i;
        memset(dis,-1,sizeof(dis));
        dis[S]=0;
        dfs1(S);
        int T=1;
        for(int i=1;i<=n;i++)if(dis[i]>dis[T])T=i;
        diam[++dl]=T;
        while(T!=S){
            T=from[T];
            diam[++dl]=T;
        }
        // for(int i=1;i<=dl;i++)printf("%d ",diam[i]);
        // printf("\n");
        diam[0]=diam[dl+1]=0;
        dep[0]=-1;
        for(int i=1;i<=dl;i++)dfs2(diam[i],diam[i-1],diam[i+1],0,i);
        pred[1]=fd[diam[1]];
        for(int i=2;i<=dl;i++)pred[i]=pred[i-1]+fd[diam[i]];
        sufd[dl]=fd[diam[dl]];
        for(int i=dl-1;i>=1;i--)sufd[i]=sufd[i+1]+fd[diam[i]];

        // for(int i=1;i<=dl;i++)printf("%d %d\n",pred[i].len,sufd[i].len);

        int L=0,R=n,B=n;
        while(L<=R){
            int mid=(L+R)/2;
            if(check(mid))B=mid,R=mid-1;
            else L=mid+1;
        }
        cout<<B<<'\n';
    }
    return 0;
}