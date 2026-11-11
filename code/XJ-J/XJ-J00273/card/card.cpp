#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;
char buf[1<<20],*p1,*p2;
#define gc() (p1 == p2 && (p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
unsigned readint(){
    int x=0,c=gc();
    for (;!isdigit(c);c=gc()) ;
    for (;isdigit(c);c=gc()) x=x*10+c-'0';
    return x;
}
const int N=5e5+10,M=3e5+10;
#define int register int
unsigned n,m,a[N],cnt[M],tmp[M],nxt[N],f[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=readint(),m=readint();
    for (int i=1;i<=n;i++) a[i]=readint();
    for (int i=n;i>=1;i--){
        nxt[i]=tmp[a[i]];
        if (!tmp[a[i]]) tmp[a[i]]=i;
    }
    cnt[a[n]]++;
    for (int t=n-1;t>=1;t--){
        int p=t;
        while (p<=n){
            while (nxt[p] > p) p=nxt[p];
            cnt[a[p]]++;
            p++;
        }
    }
    for (int i=1;i<m;i++) printf("%d ",cnt[i]);
    printf("%d\n",cnt[m]);
    return 0;
}
