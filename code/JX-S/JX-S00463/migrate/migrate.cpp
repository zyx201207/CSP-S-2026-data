#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr,__VA_ARGS__);
struct FSI{
    template<typename T>
    FSI& operator >> (T&res){
        res=0;T f=1;char ch=getchar();
        while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
        while(isdigit(ch)){res=(res*10)+(ch-48);ch=getchar();}
        res*=f;
        return *this;
    }
} scan;
const int N=2e6+5;
typedef long long ll;
ll x[N];
int pre[N],nxt[N];
namespace brute_version1{
    const int N=5005;
    int f[N][N],g[N][N];
    int kpre(int u,int k){
        return g[u][k];
        // for(int j=1;j<=k;j++) u=pre[u];
        // return u;
    }
    int knxt(int u,int k){
        return f[u][k];
        // for(int j=1;j<=k;j++) u=nxt[u];
        // return u;
    }
    void work(){
        int n;
        ll d;
        scan>>n>>d;
        for(int i=1;i<=n;i++) scan>>x[i];
        for(int i=1;i<=n;i++){
            nxt[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
            pre[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
        }
        for(int i=1;i<=n;i++){
            f[i][0]=i,g[i][0]=i;
            for(int j=1;j<=n;j++){
                f[i][j]=nxt[f[i][j-1]];
                g[i][j]=pre[g[i][j-1]];
            }
        }
        // for(int i=1;i<=n;i++) debug("%d%c",pre[i]," \n"[i==n]);
        // for(int i=1;i<=n;i++) debug("%d%c",nxt[i]," \n"[i==n]);
        int res=0;
        for(int l=1;l<=n;l++){
            int d=0,cur=l;
            for(int r=l+1;r<=n;r++){
                if(r>cur){
                    d++,cur=nxt[cur];
                }
                // debug("d(%d, %d) = %d\n",l,r,d);
                int cnt=0;
                for(int k=1;k<d;k++){
                    int R=knxt(l,k),L=kpre(r,d-k);
                    // debug("tmp = %d, seg = [%d, %d]\n",k,L,R);
                    if(R-L+1>=2){
                        cnt+=R-L+1;
                        if(cnt>2) break;
                    }  
                }
                if(cnt==2) res++;
            }
        }
        printf("%d\n",res);
    }
}
namespace dsu{
    int fa[N];
    void init(int n){
        for(int i=1;i<=n;i++) fa[i]=i;
    }
    inline int find(int x){
        while(x!=fa[x]) x=fa[x]=fa[fa[x]];
        return x;
    }
    void combine(int u,int v){
        u=find(u),v=find(v);
        if(u!=v) fa[u]=v;
    }
}
int cnt1[N],cnt2[N],ff[N];
void work(){
    int n;
    ll d;
    scan>>n>>d;
    for(int i=1;i<=n;i++) scan>>x[i];
    for(int i=1;i<=n;i++){
        nxt[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
        pre[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
    }
    // for(int i=1;i<=n;i++) debug("%d%c",nxt[i]," \n"[i==n]);
    // for(int i=1;i<=n;i++) debug("%d%c",pre[i]," \n"[i==n]);
//  good pair depend on good point, (x & x+1).
//  define a path (l->r) is good only when there is only one choice from l -> r.
//  we should count, how many path(l->x+1) is good, how many path(x->r) is good.
//  as if (l->x+1) is good and (x->r) is good, we have (l,r) good.
//  "good path" is equal relationship.
//  (u->u) is good, (u->v good) -> (v->u good), (u->v good) & (v->w good) -> (u->w) good.
//  use dsu to discribe that relationship.
    dsu::init(n);
    for(int i=1;i<n;i++){
        if(nxt[i]>i&&pre[nxt[i]]==i) dsu::combine(i,nxt[i]);
    }
    for(int l=1;l<=n;l++){
        cnt1[l]=ff[dsu::find(l)];
        ff[dsu::find(l)]++;
    }
    for(int i=1;i<=n;i++) ff[i]=0;
    for(int r=n;r>=1;r--){
        cnt2[r]=ff[dsu::find(r)];
        ff[dsu::find(r)]++;
    }
    for(int i=1;i<=n;i++) ff[i]=0;
    // for(int l=1;l<=n;l++){
    //     for(int r=l+1;r<=n;r++){
    //         if(dsu::find(l)==dsu::find(r)){
    //             cnt1[r]++,cnt2[l]++;
    //             // debug("(%d, %d) is good\n",l,r);
    //         }
    //     }
    // }
    ll res=0;
    for(int i=1;i<n;i++){
        if(nxt[i]>i+1&&pre[i+1]<i){
            // debug("try %d, %d\n",i,i+1);
            // debug("%d %d %d %d\n",pre[i+1],i,i+1,nxt[i]);
            if(nxt[pre[i+1]]==i+1&&pre[nxt[i]]==i){
                res+=1ll*(cnt1[pre[i+1]]+(nxt[pre[i+1]]<=i+1))*(cnt2[nxt[i]]+(pre[nxt[i]]>=i));
            }
        }
    }
    printf("%lld\n",res);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    scan>>c>>T;
    if(1<=c&&c<=10){
        while(T--) brute_version1::work();
    } else {
        while(T--) work();
    }
    return 0;
}