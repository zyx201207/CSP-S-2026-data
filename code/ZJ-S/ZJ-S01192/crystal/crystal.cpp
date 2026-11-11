#include<bits/stdc++.h>
// #define int long long
#define ll long long
#define ull unsigned long long
#define ld double
#define uint unsigned
#define PII pair<int,int>
#define umap unordered_map
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define rep(k,l,r) for(int k=l;k<=r;++k)
#define per(k,r,l) for(int k=r;k>=l;--k)
#define cl(f,x) memset(f,x,sizeof(f))
#define pcnt(x) __builtin_popcount(x)
#define lg(x) (31-__builtin_clz(x))
using namespace std;
void file_IO() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
}
bool M1;
const int INF=0x3f3f3f3f;
const ll INFLL=0x3f3f3f3f3f3f3f3f;
const ld eps=1e-9;
const int N=5e5+5;
ll a[N],m;
int n;
bool check(int x) {
    ll tot=0;
    rep(i,1,x-1)
        tot+=a[i];
    rep(i,x,n) {
        tot+=a[i]-a[i-x];
        if(x*a[i]-tot<=m)
            return true;
    }
    return false;
}
void solve() {
    scanf("%d%lld",&n,&m);
    rep(i,1,n)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    int l=1,r=n,ans=0;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(check(mid))
            ans=mid,l=mid+1;
        else
            r=mid-1;
    }
    printf("%d\n",ans);
}
bool M2;
// g++ crystal.cpp -std=c++14 -O2 -Wall -o crystal
signed main() {
    file_IO();
    int testcase=1;
    // scanf("%d",&testcase);
    while(testcase--)
        solve();
    debug("used time = %dms\n",(signed)(1000*clock()/CLOCKS_PER_SEC));
    debug("used memory = %dMB\n",(signed)((&M2-&M1)/1024/1024));
    return 0;
}