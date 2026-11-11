#include <bits/stdc++.h>
#define getchar() ((p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2))?EOF:*p1++)
#define putchar(c) (p3==p4? (fwrite(out,1,1<<14,stdout),p3=out):0,*p3++=(c))
#define ffflush() (p3>out?(fwrite(out,1,p3-out,stdout),p3=out):0)
static char buf[1<<14],out[1<<14],*p1=buf,*p2=buf,*p3=out,*p4=out+(1<<14);
using namespace std;
template <typename T> inline void read(T &r) {
    r=0;bool neg=false;
    char ch=getchar();
    while (ch<'0'|| ch>'9') {
        if (ch=='-') neg=true;
        if (ch==EOF) return;
        ch=getchar();
    }
    while (ch>='0' && ch<='9') {
        r=r*10+(ch-'0');
        ch=getchar();
    }
    r=(neg)?-r:r;
}
template <typename T> inline void write(T x) {
    unsigned long long u=x;
    if (x==0) {
        putchar('0');
        return;
    }
    if (x<0) {
        putchar('-');
        u=-static_cast<unsigned long long> (x);
    }
    char stk[27];int top=0;
    while (u) {
        stk[++top]=u%10+'0';
        u/=10;
    }
    while (top) putchar(stk[top--]);
}
#define int long long
const int M=5e5+7;
const int N=507;
const int INF=0x3f3f3f3f3f3f3f3f;
vector <int> lin[M];
int w[M];
int mp[N][N];
unordered_map<signed,int> dis[N];
int c,n,m,d,q;
signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(mp,0x3f,sizeof mp);
    // cin>>c>>n>>m>>d>>q;
    read(c);read(n);read(m);read(d);read(q);
    for (int i=1;i<=m;i++) read(w[i]);
    for (int i=1;i<=n;i++) {
        mp[i][i]=0;
        int k;
        read(k);
        for (int j=1;j<=k;j++) {
            int a_,t_;
            read(a_);read(t_);
            for (int olin:lin[a_]) {
                
                mp[i][olin]=min(mp[i][olin],t_+dis[olin][a_]);
                mp[olin][i]=min(mp[olin][i],mp[i][olin]);
            }
            lin[a_].push_back(i);
            dis[i][a_]=t_;
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            for (int k=1;k<=n;k++) {
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
            }
        }
    }
    while (q--) {
        int x,y;
        read(x);read(y);
        int ans=INF;
        for (int xm:lin[x]) {
            for (int ym:lin[y]) {
                ans=min(ans,mp[xm][ym]+dis[xm][x]+dis[ym][y]);
            }
        }
        // cerr<<w[x]+ans+w[y]<<'\n';
        write(w[x]+ans+w[y]);putchar('\n');
        // putchar('1');
    }
    ffflush();
}