#include<bits/stdc++.h>
#define int long long
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
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
}
bool M1;
const int INF=0x3f3f3f3f;
const ll INFLL=0x3f3f3f3f3f3f3f3f;
const ld eps=1e-9;
const int N=2e6+5;
int f[N][2],a[N],p[N];
void solve() {
    int n,d;
    scanf("%lld%lld",&n,&d);
    rep(i,1,n)
        scanf("%lld",&a[i]),f[i][0]=f[i][1]=0;
    int res=0;
    rep(i,1,n) {
        p[i]=p[i-1];
        while(p[i]!=n&&a[p[i]+1]<=a[i]+d)
            ++p[i];
        if(i>1) // = 1
            res+=(p[i-1]-max(i,p[i-2]))*f[i][0];
        // = 0
        res+=(p[i]-max(i,p[i-1]))*f[i][1];
        int c=(int)(i>1&&p[i-1]==p[i])+(int)(i>2&&p[i-2]==p[i]);
        rep(j,0,1-c)
            f[p[i]][j+c]+=f[i][j];
        ++f[p[i]][0];
    }
    printf("%lld\n",res);
}
bool M2;
// g++ migrate.cpp -std=c++14 -O2 -Wall -o migrate
signed main() {
    file_IO();
    int _,testcase=1;
    scanf("%lld%lld",&_,&testcase);
    while(testcase--)
        solve();
    debug("used time = %dms\n",(signed)(1000*clock()/CLOCKS_PER_SEC));
    debug("used memory = %dMB\n",(signed)((&M2-&M1)/1024/1024));
    return 0;
}