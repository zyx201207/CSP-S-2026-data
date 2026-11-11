#include<bits/stdc++.h>
#define cmax(a,b) a=max(a,b)
#define cmin(a,b) a=min(a,b)
#define ls p<<1
#define rs p<<1|1
#define rst(a,b) memset(a,b,sizeof(a))
#define lowbit(x) ((x)&(-x))
#define int long long
#define btp __builtin_popcount
#define pb push_back
#define inf 0x3f3f3f3f
using namespace std;

const int N(2e6+5);

int n,D,a[N],t1[N],t2[N],f[N],g[N],v1[N],v2[N];
struct node{
    int l,r;
}f1[N],f2[N];

void solve(){
    cin>>n>>D;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<=n+1;i++) f1[i]=f2[i]={0,0},t1[i]=t2[i]=f[i]=g[i]=v1[i]=v2[i]=0;
    for(int i=1,j=1;i<=n;i++){
        while(j<=n&&a[j]-a[i]<=D) j++;
        t1[i]=j-1;
        if(!f1[t1[i]].l) f1[t1[i]]={i,i};
        else f1[t1[i]].r++;
    }
    for(int i=n,j=n;i;i--){
        while(j&&a[i]-a[j]<=D) j--;
        t2[i]=j+1;
        if(!f2[t2[i]].l) f2[t2[i]]={i,i};
        else f2[t2[i]].l--;
    }
    for(int i=n-1;i;i--){
        if(i==t2[t1[i]]){
            f[i]=f[t1[i]];
        }
        if(f2[i].l) f[i]+=max(0ll,min(t1[i],f2[i].r)-max(i+1,f2[i].l)+1);
        if(i-1==t2[t1[i]]){
            v1[i]=f[t1[i]];
        }
        if(f2[i-1].l) v1[i]+=max(0ll,min(t1[i],f2[i-1].r)-max(i+1,f2[i-1].l)+1);
    }
    for(int i=2;i<=n;i++){
        if(i==t1[t2[i]]){
            g[i]=g[t2[i]];
        }
        if(f1[i].l) g[i]+=max(0ll,min(i-1,f1[i].r)-max(t2[i],f1[i].l)+1);
        if(i+1==t1[t2[i]]){
            v2[i]=g[t2[i]];
        }
        if(f1[i+1].l) v2[i]+=max(0ll,min(i-1,f1[i+1].r)-max(t2[i],f1[i+1].l)+1);
    }
    int ans=0;
    for(int i=1;i<n;i++) ans+=v1[i+1]*v2[i];
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;cin>>t>>t;
    while(t--) solve();

    
    return 0;
}