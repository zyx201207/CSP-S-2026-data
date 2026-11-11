#include<cctype>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
char buf[1048577],*p1,*p2;
#define gc() p2==p1&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p2==p1)?EOF:*p1++
void rd(int &x){
    x=0; char c=gc();
    while(!isdigit(c)) c=gc();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=gc();
}
const int N=1e6+9,M=2e6+9;
int n,k,ch[N],len,fa[N]; bool on[N];
int h[N],e[M],ne[M],idx=2;
int mxd,mid;
int st1[20][N],st2[20][N];
void dfs0(int u,int p,int d,int &A){
    if(d>mxd) A=u,mxd=d;
    fa[u]=p;
    for(int i=h[u],v;i;i=ne[i]) if((v=e[i])^p) dfs0(v,u,d+1,A);
}
int f1[N],f2[N],g[N],w[N],hei[N],son[N],h2[N],dep[N];
void getw(int u,int p){
    w[u]=0;
    for(int i=h[u],v;i;i=ne[i]) if((v=e[i])^p){
        if(on[v]) continue;
        getw(v,u);
        w[u]=max(w[u],w[v]+1);
    }
}
void dfs(int u,int p,int *f){
    f[u]=hei[u]=h2[u]=son[u]=0;
    for(int i=h[u],v;i;i=ne[i]) if((v=e[i])^p){
        dfs(v,u,f),f[u]+=f[v];
        if(hei[v]+1>=hei[u]) h2[u]=hei[u],hei[u]=hei[v]+1,son[u]=v;
        else h2[u]=max(h2[u],hei[v]+1);
    }
    f[u]+=hei[u]>=mid;
}
struct QQ{
    int a[N],q[N],hh,tt,i;
    void cl(){
        hh=0,tt=-1,i=0;
    }
    int qry(int l,int r){
        while(i<r){
            i++;
            while(hh<=tt&&a[q[tt]]<=a[i]) tt--;
            q[++tt]=i;
        }
        while(hh<=tt&&q[hh]<l) hh++;
        return a[q[hh]];
    }
}Q1,Q2;
bool find(int u,int p,int up,int tar){
    if(max(f1[u],1)<=tar&&up<=mid) return 1;
    for(int i=h[u],v;i;i=ne[i]) if((v=e[i])^p){
        if(find(v,u,max(up,hei[v]+1==hei[u]?h2[u]:hei[u])+1,tar)) return 1;
    }
    return 0;
}
void dfs2(int u,int p,int up){
    fa[u]=p;
    for(int i=h[u],v;i;i=ne[i]) if((v=e[i])^p){
        int hu=hei[v]+1==hei[u]?h2[u]:hei[u];
        g[v]=g[u]-(max(up,hei[u])>=mid)+(max(up,hu)>=mid)-(hei[v]>=mid)+(max(max(up,hu)+1,hei[v])>=mid);
        dfs2(v,u,max(up,hu)+1);
    }
}
bool chk(){
    Q1.cl(),Q2.cl();
    dfs(ch[len],0,f1),dfs(ch[1],0,f2);
    for(int i=1;i<=len;i++) Q1.a[i]=w[ch[i]]+i,Q2.a[i]=w[ch[i]]-i;
    // printf("mid %d\n",mid);
    // for(int i=1;i<=len;i++) printf("%d ",f1[ch[i]]); puts("");
    // for(int i=1;i<=len;i++) printf("%d ",f2[ch[i]]); puts("");
    for(int i=1,j=1;i<=len;i++){
        j=max(j,i+1);
        while(j<=len&&max(f1[ch[i]],1)+max(f2[ch[j]],1)>k) j++;
        if(j>len) break;
        // printf("ij %d %d %d %d %d %d %d ",i,j,k,f1[ch[i]],f2[ch[j]],Q1.qry(i+1,i+j>>1)-i,Q2.qry(i+j+1>>1,j-1)+j);
        // printf("%d\n",Q1.q[Q1.hh]);
        if(i+1==j) return 1;
        if(Q1.qry(i+1,i+j>>1)-i<=mid&&Q2.qry(i+j+1>>1,j-1)+j<=mid) return 1;
    }
    // puts("GG");
    int md=ch[len+1>>1],tot=1;
    dfs(md,0,f1),g[md]=f1[md],dfs2(md,0,0);
    for(int i=1;i<=n;i++) if(son[fa[i]]^i){
        Q1.cl(),Q2.cl();
        static int nd[N];
        {
            int x=i,d=0;
            while(x){
                nd[dep[x]=++d]=x;
                // printf("nd %d %d\n",d,x);
                Q1.a[d]=h2[x]+dep[x],Q2.a[d]=h2[x]-dep[x];
                x=son[x];
            }
        }
        int x=son[i],t=0,y;
        // printf("%d %d %d: ",i,h2[i],f1[i]);
        while(x){
            while(t+1<dep[x]&&max(Q1.qry(t+1,t+dep[x]>>1)-dep[x],Q2.qry(t+dep[x]+1>>1,dep[x]-1)+dep[x])>mid) t++;
            if(!t) y=i==md?0:max(g[fa[i]],1)-f1[i];
            else y=max(g[nd[t]],1)-f1[nd[t+1]];
            // printf("%d %d %d %d  ",x,t,!t?fa[i]:fa[nd[t]],y);
            if(y+max(f1[x],1)<=k) return 1;
            x=son[x];
        }
        // puts("");
    }
    return 0;
}
void solve(){
    rd(n),rd(k);
    for(int i=1;i<=n;i++) h[i]=0,on[i]=0; idx=2;
    for(int i=1,a,b;i<n;i++){
        rd(a),rd(b);
        e[idx]=b,ne[idx]=h[a],h[a]=idx++;
        e[idx]=a,ne[idx]=h[b],h[b]=idx++;
    }
    {
        int A=1; mxd=0; dfs0(1,0,0,A);
        int B=A; mxd=0; dfs0(A,0,0,B);
        ch[len=1]=B;
        while(B^A) B=fa[B],ch[++len]=B;
        for(int i=1;i<=len;i++) on[ch[i]]=1;
        // for(int i=1;i<=len;i++) printf("%d ",ch[i]); puts("");
        for(int i=1;i<=len;i++) getw(ch[i],0),Q1.a[i]=w[ch[i]]+i,Q2.a[i]=w[ch[i]]-i;
        // for(int i=1;i<=len;i++) printf("%d ",w[ch[i]]); puts("");
    }
    // mid=2,printf("%d\n",chk()); return;
    int l=0,r=len-1>>1;
    while(l<r){
        mid=l+r>>1;
        if(chk()) r=mid;
        else l=mid+1;
    }
    printf("%d\n",r);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int SJQ,T; rd(SJQ),rd(T);
    while(T--) solve();
    return 0;
}