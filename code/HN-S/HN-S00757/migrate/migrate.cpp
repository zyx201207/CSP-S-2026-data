#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long
#define pii pair<int,int> 
#define popc __builtin_popcount
#define All(v) (v).begin(),(v).end()
#define lowbit(x) ((x)&(-(x)))
const int N=2e6+5;
int n,fa[N],nxt[N],head[N];
int lim[N];
ll a[N];
inline ll read(){
    ll x(0),t(0);
    static char ch=getchar();
    while(!isdigit(ch)) t|=ch=='-',ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return t?-x:x;
}
int s[N],siz[N];
ll w1[N],w2[N];
ll res=0;
int sta[N],tp;
inline int Find(int L,int R,int x){
    if(lim[L]<=x&&lim[R]>=x){
        int l=L,r=R;
        while(l<r){
            int mid=l+r+1>>1;
            if(lim[mid]<=x) l=mid;
            else r=mid-1;
        }
        int RR=r;
        l=L,r=R;
        while(l<r){
            int mid=l+r>>1;
            if(lim[mid]>=x) r=mid;
            else l=mid+1;
        }
        return RR-r+1;
    }
    return 0;
}
inline void dfs(int x){
    sta[++tp]=x;
    siz[x]=siz[fa[x]];
    s[x]=s[fa[x]];
    w1[x]=w1[fa[x]];
    w2[x]=w2[fa[x]];
    if(fa[x]){
        siz[x]+=lim[fa[x]]==x-1;
        w1[x]+=Find(x+1,fa[x],x);
        if(lim[fa[x]-1]==x&&fa[fa[x]]) w2[fa[x]]=w2[fa[fa[x]]]+Find(fa[x]+1,fa[fa[x]],fa[x]-1);
        w2[x]=w2[fa[x]];
    }
    if(fa[fa[x]]){
        int j=fa[x];
        if(lim[fa[j]]<=j-2);
        else{
            int lst,tplst;
            {
                int l=3,r=tp-1;
                while(l<r){
                    int mid=l+r>>1;
                    if(siz[fa[x]]-siz[sta[mid]]>=2||s[x]-s[sta[mid]]) l=mid+1;
                    else r=mid;
                }
                tplst=r;
                lst=sta[r];
            }
            int llst;
            {
                int l=tplst-1,r=tp-1;
                while(l<r){
                    int mid=l+r+1>>1;
                    if(siz[fa[x]]-siz[sta[mid]]) l=mid;
                    else r=mid-1;
                }
                llst=sta[r];
            }
            res+=w2[fa[x]]-w2[llst];
            res+=w1[llst]-w1[fa[lst]];
            j=fa[x];
            if(w2[j]==w2[fa[j]]) res+=Find(j+1,fa[j],j-1);
        }
        if(lim[fa[j]]<=j-2||lim[fa[j]]==j-1&&lim[j-1]<=x-1) s[j]=s[fa[j]]+1;
        else s[j]=s[fa[j]];
        s[x]=s[j];
    }
    for(int y=head[x];y;y=nxt[y]) dfs(y);
    if(fa[fa[x]]) s[fa[x]]=s[fa[fa[x]]],w2[fa[x]]=w2[fa[fa[x]]];
    tp--;
}
inline void work(){
    n=read();
    fill(head,head+1+n,0);
    ll d=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=n,j=n;i;i--){
        while(a[j]-a[i]>d) j--;
        fa[i]=j;
        if(i==j) fa[i]=0;
        nxt[i]=head[fa[i]];
        head[fa[i]]=i;
    }
    for(int i=1,j=1;i<=n;i++){
        while(a[i]-a[j]>d) j++;
        lim[i]=j;
    }
    res=0;
    dfs(0);
    cout<<res<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int _=read();
    int t=read();
    while(t--) work();
    return 0;
}
// Oct31==Dec25?