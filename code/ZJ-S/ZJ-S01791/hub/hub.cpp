#include<bits/stdc++.h>
#define For(i,l,r) for(int i=(l);i<=(r);i++)
#define inf (int)(1e18)
using namespace std;
inline int rd(){
    int x=0,f=0;char c=getchar();
    while(!isdigit(c)) f=(c=='-'),c=getchar();
    while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return f?-x:x;
}
const int N=1e6+10;
vector<pair<int,int> >g[N];
int n,k,a[N],b[N],ban,mx[N],mn,mxf[N],sz[N],lim;
inline void dfs1(int x,int fa){//计算深度
    mx[x]=0;
    sz[x]=0;
    for(int i=0;i<g[x].size();i++){
        int v=g[x][i].first;
        if(v==fa||g[x][i].second==ban) continue;
        dfs1(v,x);
        sz[x]+=sz[v];
        mx[x]=max(mx[x],mx[v]+1);
    }
    sz[x]+=(mx[x]>=lim);
}
inline void dfs2(int x,int fa){
    int cnt=0,_mx=0;
    for(int i=0;i<g[x].size();i++){
        int v=g[x][i].first;
        if(v==fa||g[x][i].second==ban) continue;
        if((mx[v]+1)==mx[x]) cnt++;
        else _mx=max(_mx,mx[v]+1);
    }
    // printf("!%d %d %d\n",x,_mx,cnt);
    for(int i=0;i<g[x].size();i++){
        int v=g[x][i].first;
        if(v==fa||g[x][i].second==ban) continue;
        int nv;
        if(mx[x]==(mx[v]+1)){
            if(cnt>1) nv=mx[x];
            else nv=_mx;
        }else nv=mx[x];
        mxf[v]=max(mxf[x],nv)+1;
        dfs2(v,x);
    }
    // if(mxf[x]==0) printf("!!%d\n",x);
    // printf("%d %d %d %d\n",x,mx[x],sz[x],mxf[x]);
    if(mxf[x]<=lim){
        
        mn=min(mn,sz[x]-(mx[x]>=lim)+1);
        // if(mn==1) printf("!%d %d %d %d\n",mx[x],mxf[x],lim,sz[x]);
    }
}
bool check(int x){
    lim=x;
    // int mn=k;
    mn=n;
    ban=-1;
    mxf[1]=0;
    dfs1(1,0);
    dfs2(1,0);
    if(mn<=k) return 1;
    For(i,1,n-1){
        ban=i;
        mn=n;
        mxf[a[i]]=mxf[b[i]]=0;
        dfs1(a[i],0);
        dfs2(a[i],0);
        // printf("1:%d\n",mn);
        // printf("??%d %d\n",a[i],b[i]);
        int nv=mn;
        mn=n;
        dfs1(b[i],0);
        dfs2(b[i],0);
        // printf("2:%d\n",mn);
        if(nv&&mn&&(nv+mn)<=k){
            // printf("%d %d %d\n",i,nv,mn);
            return 1;
        }
    }
    return 0;
}
void solve(){
    n=rd();k=rd();
    For(i,1,n) g[i].clear();
    For(i,1,n-1){
        a[i]=rd();b[i]=rd();
        g[a[i]].push_back(make_pair(b[i],i));
        g[b[i]].push_back(make_pair(a[i],i));
    }
    // if(id==1) return ;
    // puts("!!!");
    int l=1,r=n,ans=n;
    // printf("%d\n",check(9));
    // printf("%d\n",check(2));
    // For(i,1,n) printf("%d ",check(i));
    // printf("\n");
    // printf("!%d\n",ans);
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",ans);
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    // puts("123");
    int c=rd(),T=rd();
    while(T--) solve();
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/