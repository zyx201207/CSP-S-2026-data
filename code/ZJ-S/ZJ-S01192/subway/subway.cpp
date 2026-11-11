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
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
}
bool M1;
const int INF=0x3f3f3f3f;
const ll INFLL=0x3f3f3f3f3f3f3f3f;
const ld eps=1e-9;
const int N=5e2+5,M=5e5+5;
int read() {
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)) {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
        x=x*10+ch-48,ch=getchar();
    return x*f;
}
vector<PII> vec[M];
int a[M];
ll f[N][N];
void solve() {
    int _=read(),n=read(),m=read(),d=read(),q=read();
    rep(i,1,m)
        a[i]=read();
    rep(i,1,n) {
        int k=read();
        while(k--) {
            int x=read(),y=read();
            vec[x].push_back(make_pair(i,y));
        }
    }
    cl(f,0x3f);
    rep(i,1,n)
        f[i][i]=0;
    rep(i,1,m) {
        for(auto x:vec[i]) {
            for(auto y:vec[i])
                chkmin(f[x.first][y.first],(ll)x.second+y.second);
        }
    }
    rep(k,1,n) {
        rep(i,1,n) {
            rep(j,1,n)
                chkmin(f[i][j],f[i][k]+f[k][j]);
        }
    }
    while(q--) {
        int u=read(),v=read();
        ll res=INFLL;
        for(auto x:vec[u]) {
            for(auto y:vec[v])
                chkmin(res,f[x.first][y.first]+x.second+y.second);
        }
        printf("%lld\n",res+a[u]+a[v]);
    }
}
bool M2;
// g++ subway.cpp -std=c++14 -O2 -Wall -o subway
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