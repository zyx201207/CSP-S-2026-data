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
#define cerr if (0) cerr
#define int long long
const int N=2e6+7;
const int INF=0x3f3f3f3f3f3f3f3f;
int a[N];
int cnt[N];
int dis[N];
queue <int> Q;
void work() {
    int n,d;
    read(n);read(d);
    for (int i=1;i<=n;i++) {
        read(a[i]);
    }
    int ans=0;
    for (int i=1;i<=n;i++) {
        for (int j=i;j<=n;j++) {
            cnt[j]=0;
            dis[j]=INF;
        }
        cnt[i]=1;
        dis[i]=0;
        while (!Q.empty()) Q.pop();
        Q.push(i);
        while (!Q.empty()) {
            int cur=Q.front();Q.pop();
            int nxt=cur+1;
            while (nxt<=n && a[nxt]-a[cur]<=d) {
                cerr<<"nxt2:"<<nxt<<"dis[nxt]:"<<dis[nxt]<<" dis[cur]:"<<dis[cur]<<endl;
                if (dis[nxt]>dis[cur]+1) {
                    // cerr<<"nxt:"<<nxt<<endl;
                    cnt[nxt]=cnt[cur];
                    dis[nxt]=dis[cur]+1;
                    Q.push(nxt);
                } else if (dis[nxt]==dis[cur]+1) {
                    cnt[nxt]+=cnt[cur];
                }
                nxt++;
            }
        }
        for (int j=i+1;j<=n;j++) {
            if (cnt[j]==2) ans++;
        }
    }
    write(ans);putchar('\n');
}
void work2() {
    int n,d;
    read(n);read(d);
    int qlen=0;
    for (int i=1;i<=n;i++) {
        read(a[i]);
        if (a[i]-a[1]<=d) qlen=i-1;
    }
    int ans=0;
    for (int i=1;i<=n;i++) {
        if (qlen<=1) continue;
        if (i+qlen+qlen-1<=n) ans++;
    }
    write(ans);putchar('\n');
}
void work3() {
    int n,d;
    read(n);read(d);
    for (int i=1;i<=n;i++) {
        read(a[i]);
    }
    int ans=0;
    for (int i=1;i<=n;i++) {
        int fj=upper_bound(a+1+i,a+1+n,a[i]+d)-a-1;
        
        if (fj==i+1) continue;
        int lfj=fj-1;
        int llfj=lfj-1;
        int nxt1=upper_bound(a+1+i,a+1+n,a[lfj]+d)-a-1;
        nxt1=min(nxt1,n);
        int nxt2=upper_bound(a+1+i,a+1+n,a[llfj]+d)-a;
        if (nxt2>n) continue;
        if (nxt2>nxt1) continue;
        cerr<<"i:"<<i<<" "<<fj<<" "<<nxt1<<" "<<nxt2<<endl;
        ans+=nxt1-nxt2+1;
    }
    write(ans);putchar('\n');
}
signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    read(c);read(t);
    if (c<11) while (t--) work();
    else if(c<=12)   while (t--) work2();
    else  
    while (t--) work3();
    ffflush();
}