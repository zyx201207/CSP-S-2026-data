#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;

int read() {
    int s=0;
    char c=getchar();
    while(c<'0' || c>'9') c=getchar();
    while(c>='0' && c<='9') s=s*10+c-'0',c=getchar();
    return s;
}

int cid;
int T;
int n,m;
vector<int> g[N];
int pre[N];
vector<int> dia;
vector<int> bel[N];
int bb[N];
bool ond[N];
int dep[N],mxd[N],mxd2[N],mxo[N];
int dfn[N],num,rnk[N];
int siz[N],son[N],f[N],top[N];
vector<int> chain[N];
vector<int> ad[N];
int cd[N];

void dfs1(int u,int fa,int d,pair<int,int> &mx) {
    pre[u]=fa;
    mx=max(mx,{d,u});
    for(int v:g[u]) {
        if(v==fa) continue;
        dfs1(v,u,d+1,mx);
    }
}

void dfs2(int u,int fa,int b) {
    bb[u]=b;
    f[u]=fa;
    chain[u].clear();
    bel[b].push_back(u);
    dep[u]=dep[fa]+1;
    mxd[u]=mxd2[u]=0;
    siz[u]=1;
    son[u]=0;
    for(int v:g[u]) {
        if(v==fa || ond[v]) continue;
        dfs2(v,u,b);
        siz[u]+=siz[v];
        if(mxd[v]+1>mxd[u]) mxd2[u]=mxd[u],mxd[u]=mxd[v]+1,son[u]=v;
        else mxd2[u]=max(mxd2[u],mxd[v]+1);
    }
}

void dfs3(int u,int fa) {
    for(int v:g[u]) {
        if(v==fa || ond[v]) continue;
        mxo[v]=mxo[u]+1;
        if(mxd[v]+1==mxd[u]) mxo[v]=max(mxo[v],mxd2[u]+1);
        else mxo[v]=max(mxo[v],mxd[u]+1);
        dfs3(v,u);
    }
}

void dfs4(int u,int tp) {
    top[u]=tp;
    dfn[u]=++num,rnk[num]=u;
    chain[tp].push_back(u);
    if(son[u]) dfs4(son[u],tp);
    for(int v:g[u]) {
        if(v==f[u] || ond[v] || v==son[u]) continue;
        dfs4(v,v);
    }
}

void init() {
    pair<int,int> mx={0,0};
    dfs1(1,0,0,mx);
    int p=mx.second;
    mx={0,0};
    dfs1(p,0,0,mx);
    int x=mx.second;
    dia.clear();
    for(int i=1;i<=n;i++) ond[i]=0,bel[i].clear();
    while(x) {
        dia.push_back(x);
        ond[x]=1;
        x=pre[x];
    }
    num=0;
    for(int x:dia) {
        dfs2(x,0,x);
        mxo[x]=0;
        dfs3(x,0);
        dfs4(x,x);
    }
    for(int i=1;i<=n;i++) cd[i]=0;
    for(int i=1;i<=n;i++) cd[dep[i]]++;
    for(int i=1;i<=n;i++) ad[i].reserve(cd[i]);
}

vector<int> calc(int mid) {
    vector<int> c(dia.size());
    vector<int> inst(dia.size());
    static int mnt[N<<1];
    int lst=0;
    for(int i=0;i<dia.size();i++) {
        for(int j=lst;j<=mxd[dia[i]]+i;j++) mnt[j]=i;
        lst=max(lst,mxd[dia[i]]+i+1);
    }
    for(int j=lst;j<=n*2;j++) mnt[j]=dia.size();
    lst=0;
    for(int i=0;i<dia.size();i++) {
        while(lst<=i && i-lst+mxd[dia[i]]>=mid) inst[lst++]=i;
    }
    while(lst<dia.size()) inst[lst++]=dia.size();
    for(int i=(int)dia.size()-1;i>=0;i--) {
        int x=dia[i];
        for(int u:bel[x]) {
            if(mxd[u]>=mid && mxd2[u]>=mid) c[i]++;
            else if(mxd[u]>=mid) {
                if(mxo[u]>=mid) c[i]++;
                else {
                    if(i+dep[u]-1>=mid) c[i]++;
                    else if(mnt[mid+i-dep[u]+1]<c.size()) c[mnt[mid+i-dep[u]+1]]++;
                }
            }
            else if(u==x) {
                if(i>=mid && inst[i]<c.size()) c[inst[i]]++;
            }
        }
    }
    for(int i=1;i<c.size();i++) c[i]+=c[i-1];
    for(int &i:c) i=max(i,1);
    return c;
}

bool chose[N];
int limd[N],ps[N];
int d1[N],d2[N],sizc[N];

void dfs5(int u,int fa,int mid) {
    limd[u]=dep[u];
    ad[dep[u]].push_back(u);
    for(int v:g[u]) {
        if(v==fa || ond[v]) continue;
        dfs5(v,u,mid);
        int od=mxd[u]+1;
        if(mxd[v]+1==mxd[u]) od=mxd2[u]+1;
        while(limd[v]>dep[u] && limd[v]-dep[u]+od>=mid) {
            while(ad[limd[v]].size()) {
                int x=ad[limd[v]].back();
                if(bb[x]==bb[u] && dfn[x]>=dfn[v] && dfn[x]<dfn[v]+siz[v]) {
                    ps[x]=u;
                    ad[limd[v]].pop_back();
                }
                else break;
            }
            limd[v]--;
        }
        limd[u]=max(limd[u],limd[v]);
    }
}

bool chk2(int mid) {
    // for(int i:dia) printf("%d ",i);printf("\n");
    static int id[N];
    for(int i=0;i<dia.size();i++) {
        int x=dia[i];
        id[x]=i;
        for(int u:bel[x]) {
            chose[u]=0;
            if(u==x) {
                if((mxd[u]>=mid)+(mxd2[u]>=mid)+(i>=mid)+(dia.size()-i-1>=mid)>=2) chose[u]=1;
            }
            else {
                if((mxd[u]>=mid)+(mxd2[u]>=mid)+(mxo[u]>=mid)>=2) chose[u]=1;
                else {
                    if(mxd[u]>=mid) {
                        if(i>=mid || (int)dia.size()-i-1>=mid) chose[u]=1;
                    }
                }
            }
        }
    }
    int c=0;
    for(int i=1;i<=n;i++) c+=chose[i];
    if(c<=m) return 1;
    // printf("%d\n",c);
    // if(cid>8) return 0;
    for(int i=1;i<=n;i++) d1[i]=d2[i]=0,sizc[i]=chose[i];
    for(int i=1;i<=n;i++) if(top[i]==i) {
        // printf("%d:\n",i);
        int p=0;
        for(int j=0;j<chain[i].size();j++) {
            while(p<chain[i].size() && mxd2[chain[i][p]]+p-j<mid) p++;
            int u=chain[i][j];
            // printf(" %d\n",u);
            if(chose[u]) {
                int co=0;
                if(ond[u]) co=(id[u]>=mid)+((int)dia.size()-id[u]-1>=mid);
                else co=mxo[u]>=mid || dep[u]-1+id[bb[u]]>=mid || dep[u]-1+(int)dia.size()-id[bb[u]]-1>=mid;
                if(co==1 && p<chain[i].size()) d1[chain[i][p]]++,d1[u]--;
            }
        }
    }
    for(int i=1;i<=n;i++) ad[i].clear();
    for(int x:dia) {
        for(int i:bel[x]) ps[i]=limd[i]=0;
        dfs5(x,0,mid);
        for(int u:bel[x]) if(chose[u] && !ond[u]) {
            if(ps[u] && mxd[u]>=mid && mxd2[u]<mid) d2[u]++,d2[ps[u]]--;
        }
    }
    for(int i=n;i>=1;i--) {
        int u=rnk[i];
        for(int v:g[u]) {
            if(dep[v]<dep[u] || ond[v]) continue;
            d1[u]+=d1[v];
            d2[u]+=d2[v];
            sizc[u]+=sizc[v];
        }
        if(!ond[u] && c-d1[u]-d2[u]+(d2[u]==sizc[u])<=m) return 1;
    }
    return 0;
}

bool chk(int mid) {
    if(!mid) return m>=n;
    vector<int> c1=calc(mid);
    reverse(dia.begin(),dia.end());
    vector<int> c2=calc(mid);
    for(int i=1;i<dia.size();i++) if(c1[i-1]+c2[(int)dia.size()-i-1]<=m) return 1;
    if(chk2(mid)) return 1;
    return 0;
}

int main() {
    freopen("data.in","r",stdin);
    freopen("my.out","w",stdout);
    cid=read(),T=read();
    while(T--) {
        n=read(),m=read();
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++) {
            int u=read(),v=read();
            g[u].push_back(v),g[v].push_back(u);
        }
        init();
        int L=0,R=n,mid,res=n;
        while(L<=R) {
            mid=L+R>>1;
            if(chk(mid)) res=mid,R=mid-1;
            else L=mid+1;
        }
        printf("%d\n",res);
    }
    return 0;
}
//18:12