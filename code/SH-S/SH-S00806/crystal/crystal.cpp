#include <bits/stdc++.h>
#define eputs(str) fputs(str"\n",stderr)
#define eprintf fprintf
#define dbgo stderr 
using namespace std;
#define ll long long
const int MAXN=5e5+10;
int n;
ll m;
ll a[MAXN];
void input(){
    scanf("%d%lld",&n,&m);
    memset(&a[0],0x80,sizeof(ll));
    for (int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
}
namespace c50{
    bool vis[5010];
    void solve(){
        //eputs("c50");
        int ans=0,tag=0;
        sort(a+1,a+n+1);
        for (int i=1;i<=n;++i){
            int cans=1;
            ll cm=m;
            for (int j=i-1;j>=1;--j){
                cm-=a[i]-a[j];
                if (cm>=0)++cans;
                else break;
            }
            //fprintf(stderr,"%lld:%d\n",a[i],cans);
            if (cans>ans)ans=cans,tag=a[i];
        }              
        printf("%d\n",ans);
        //eputs("finish");
    }
}
namespace c100{
    ll diff[MAXN];
    const int MAXN=1e5+10;
    ll tree[MAXN<<2],lazy[MAXN<<2],a[MAXN];
    int M;
    void build(int n){
        for (M=1;M<=n+1;M<<=1);
        for (int i=1;i<=M<<1;++i){
            tree[i]=lazy[i]=0;
        }
    }
    void modify(int l,int r,ll v){
        int s=M+l-1,t=M+r+1,llen=0,rlen=0,len=1;
        for (;s^t^1;s>>=1,t>>=1,len<<=1){
            tree[s]+=v*llen,tree[t]+=v*rlen;
            if (~s&1) tree[s^1]+=v*len,lazy[s^1]+=v,llen+=len;
            if (t&1)tree[t^1]+=v*len,lazy[t^1]+=v,rlen+=len;
        }
        for (;s;s>>=1,t>>=1){
            tree[s]+=v*llen,tree[t]+=v*rlen;
        }
    }
    ll query(int l,int r){
        int s=M+l-1,t=M+r+1,llen=0,rlen=0,len=1;
        ll lans=0,rans=0;
        for (;s^t^1;s>>=1,t>>=1,len<<=1){
            lans+=lazy[s]*llen,rans+=lazy[t]*rlen;
            if (~s&1) lans+=tree[s^1],llen+=len;
            if (t&1) rans+=tree[t^1],rlen+=len;
        }
        for (;s;s>>=1,t>>=1){
            lans+=lazy[s]*llen,rans+=lazy[t]*rlen;
        }
        return lans+rans;
    }
    int find(int c,int m){
        int l=1,r=c;
        while(l<=r){
            int mid=(l+r)>>1;
            if (query(mid,c)<=m){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return l;
    }
    void solve(){
        //eputs("c50");
        int ans=0;
        sort(a+1,a+n+1);
        for (int i=1;i<n;++i){
            diff[i]=a[i+1]-a[i];
        }
        for (int i=2;i<=n;++i){
            ans=max(ans,n-find(i-1,m));
            fprintf(stderr,"%d:%d",i,find(i,m));
            if (i!=n) modify(1,i,diff[i]);
        }
        printf("%d\n",ans);
        //eputs("finish");
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //eputs("ok1");
    int t=1;
    for (int _=1;_<=t;++_){
        input();
        c50::solve();

    }
    fflush(NULL);
    return 0;
}