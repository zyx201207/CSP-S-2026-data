#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cassert>
#include<algorithm>
using std::cin;
using std::cout;
#define db(x...) fprintf(stderr,x)
struct Code {
    Code() {
        freopen("migrate.in","r",stdin);
        freopen("migrate.out","w",stdout);
        std::ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
    }
    ~Code() {
        cout.flush();
        fclose(stdin);
        fclose(stdout);
    }
} code;
using i64=long long;
const int N=2e6+11;
int n;
i64 d,x[N];
int f[N],g[N],nx[N],tnx[N];
bool is[N];
void clr() {
    memset(f+1,0,n<<2);
    memset(g+1,0,n<<2);
    memset(is+1,0,n);
}
// int qry(i64 l,i64 r) {
//     // assert(l<=r);
//     // db("%lld,%lld\n",l,r);
//     return std::upper_bound(x+1,x+n+1,r)-std::lower_bound(x+1,x+n+1,l);
// }
void slv() {
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    i64 rs=0;
    for(int i=n,r=n;i>=1;i--) {
        while(x[r]>x[i]+d) r--;
        nx[i]=r;
        // db("\n\ni=%d\n",i);
        // nx[i]=std::upper_bound(x+1,x+n+1,x[i]+d)-x-1;
        // db("  nx,tnx=%d,%d\n",nx[i],tnx[i]);
        int j=nx[i],k=nx[nx[i]];
        // db("  j=%d,k=%d\n",j,k);
        if(j==i||k==j) continue;
        if(j>i+1) rs+=nx[j-1]-nx[j-2];
        // rs+=qry(x[j-2]+d+1,x[j-1]+d);
        // ,db("    %lld,%lld\n",x[j-2]+d+1,x[j-1]+d);
        // db("  add 2: %lld\n",rs);
        if(j>i+1&&x[k]-x[j-2]<=d) continue;
        if(x[k]-x[j-1]<=d) {
            g[i]+=f[j];
            g[i]+=nx[k]-nx[k-1];
            // g[i]+=qry(x[k-1]+d+1,x[k]+d);
            is[i]=1;
        }
        else {
            // db("  case2\n");
            f[i]+=f[j];
            f[i]+=nx[k]-nx[k-1];
            // f[i]+=qry(x[k-1]+d+1,x[k]+d);
            if(k>j+1&&x[k-1]-x[j-1]>d) {
                g[i]+=g[j];
                g[i]+=nx[k-1]-nx[k-2];
                // g[i]+=qry(x[k-2]+d+1,x[k-1]+d);    
            }
            else if(!is[j]) g[i]+=g[j];
        }
        rs+=g[i];
        // db("  f=%d,g=%d\n",f[i],g[i]);
        // db("  end: %lld\n",rs);
    }
    cout<<rs<<'\n';
}
int main() {
    int tid,T; cin>>tid>>T;
    while(T--) slv(),clr();
    return 0;
}