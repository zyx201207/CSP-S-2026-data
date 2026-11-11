#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N=2e6+10,M=1e6+10;
#define For(a,b,c) for(int a=(b);a<=(LL)(c);a++)
#define Rep(a,b,c) for(int a=(b);a>=(LL)(c);a--)
// #define debug

LL INF=0x3f3f3f3f3f3f3f3f;

template <typename T> void tomin(T &a,const T &b){a=a<b?a:b;}
template <typename T> void tomax(T &a,const T &b){a=b<a?a:b;}

template <typename T> void read(T &x){
    T f=0,w=1;
    int ch=getchar();
    while(!isdigit(ch)){if(ch=='-') w=-w;ch=getchar();}
    while(isdigit(ch)) {f=(f<<3)+(f<<1)+ch-48;ch=getchar();}
    x=f*w;
}

int C;

int n;
LL d,a[N];
int nxt[N], pre[N];

namespace S1{
    const int N=510;
    int f[N][N];
    bool check(int u,int v){
        int d=0;
        if(f[u][v]==-1) return 0;
        For(i,u,v-1){
            if(f[u][i]!=f[u][i+1]) continue;
            if(f[u][i]+f[i][v]==f[u][v]) d++;//belike Floyd.
            if(d>1) break;
        }
        return d==1;
    }
    void solve(){
        #ifdef debug
            cerr<<"in S1 \n";
        #endif
        int res=0;
        Rep(i,n,1){
            f[i][i]=0;
            For(j,i+1,n){
                f[i][j]=-1;
                if(f[nxt[i]][j]==-1) continue;
                f[i][j] = f[nxt[i]][j]+1;
            }
        }
        For(i,1,n){
            For(j,i+1,n){
                int w=check(i,j);
                res+=w;
                #ifdef debug
                    if(w) cerr<<"("<<i<<", "<<j<<") is useful\n";
                #endif
            }
        }
        printf("%d\n",res);
    }
}

namespace S2{
    int d1[N],d2[N];
    void solve(){
        //let's guess ans!
        #ifdef debug
            cerr<<"in S2\n";
        #endif
        For(i,1,n) d1[i]=0, d1[i]=1+(nxt[pre[i]]==i?d1[pre[i]]:0);
        Rep(i,n,1) d2[i]=0, d2[i]=1+(pre[nxt[i]]==i?d2[nxt[i]]:0);
        LL res=0;
        For(i,1,n-1){
            //can choose u->a1->a2->...->i->b1->b2->...->v
            //or can choose u->a1->a2->...->i+1->b1->b2->...->v
            if(nxt[i]==i+1 || pre[i+1]==i || nxt[i]==i) continue;
            int x=pre[i+1],y=nxt[i];
            if(nxt[x]!=i+1||pre[y]!=i) continue;
            LL w=1ll*d1[x]*d2[y];
            #ifdef debug
                cerr<<"i="<<i <<" x="<<x <<" y="<<y <<" w="<<w<<"\n";
            #endif
            res+=w;
        }
        printf("%lld\n",res);
    }
}

namespace S3{
    void solve(){
        LL D=a[2]-a[1];
        d/=D;
        if(d<=1) return puts("0"),void();
        LL res=0;
        For(u,1,n){
            int v=u+2*d-1;
            if(v>n) break;
            res++;
        }
        printf("%lld\n",res);
    }
}

void awa(){
    read(n),read(d);
    For(i,1,n) read(a[i]);
    int p=1;
    For(i,1,n){
        while(p<n&&a[p+1]-a[i]<=d) p++;
        nxt[i]=p;
    }
    p=n;
    Rep(i,n,1){
        while(p>1&&a[i]-a[p-1]<=d) p--;
        pre[i]=p;
    }
    if(1<=C&&C<=6) return S1::solve();//6 tests, 24pts.
    if(11<=C&&C<=12) return S3::solve();//2 tests, 8pts.
    return S2::solve();
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T=1;
    read(C), read(T);
    while(T--) awa();
    cerr<<clock()/1000.0<<"ms\n";
    return 0;
}
/*

We find that, if it's dengcha shulie, only v=u+2d-1&&d!=1 can res++.

Cool!(It's a cold xiaohua...I'm hot, so I want cool!)

16:22~16:53 S1

let's guess!

can't guess QAQ

*/
