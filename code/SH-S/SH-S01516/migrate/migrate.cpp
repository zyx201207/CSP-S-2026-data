#include<bits/stdc++.h>
using namespace std;

bool bg_M;
template<typename T>
void read(T &a){
    char c;a=0;int f=1;
    while(!isdigit(c=getchar()))if(c=='-')f=-1;
    do a=a*10+c-'0';
    while(isdigit(c=getchar()));
    a*=f;
}
template<typename T>
void write(T a){
    if(a<0)putchar('-'),a=-a;
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
typedef long long ll;
namespace ZZOI{
//// clear multitests!!!
int C;
int n;ll d;
const int MAXN=2000'010;
ll a[MAXN],ansa[MAXN];
ll b[MAXN],ansb[MAXN];
void solve(ll c[MAXN],ll ans[MAXN]){
    // for(int i=1;i<=n;++i)printf("%lld ",c[i]);puts("");
    auto ask=[&](ll x,ll y)->int {
        // printf("? %d %d - %lld %lld\n",upper_bound(c,c+n+1,y)-c,lower_bound(c,c+n+1,x)-c,x,y);
        if(x>y)return 0;
        int res=upper_bound(c+1,c+n+1,y)-lower_bound(c+1,c+n+1,x);
        return res;
    };
    for(int k=2;k<=n-2;++k){
        ll l=c[k+1]-d,r=min(c[k]-1,c[k+2]-1-d);
        ans[k]=0;
        int t=ask(l,r);
        if(!t)continue;
        ans[k]+=t;
        int L=lower_bound(c+1,c+n+1,l)-c,R=k;
        // printf("lr %lld %lld %d - %d %d\n",l,r,t,L,R);
        // int cc=0;
            // if(k==4)
            // printf("nL %d\n",L);
        while(L>1){
            if(c[L-1]+d>=c[R])break;
            l=c[L]-d,r=min(c[L]-1,c[L+1]-1-d);
            t=ask(l,r);
            
            if(!t)break;
            ans[k]+=t;
            R=L,L=lower_bound(c+1,c+n+1,l)-c;
            // if(k==4)
            // printf("nL %d\n",L);
            // ++cc;
            // printf("? %d %d %lld %lld %lld k=%d\n",L,R,c[L],c[L+1],d,k);
        }
        // cerr<<"k "<<k<<" "<<cc<<endl;
    }
    // for(int i=1;i<=n;++i)printf("%lld ",ans[i]);puts("");
}

void main(){
    read(n),read(d);
    for(int i=1;i<=n;++i)read(a[i]),b[n-i+1]=-a[i];
    if(n==1)return puts("0"),void();
    if(C==11||C==12){
        ll D=min(d/(a[2]-a[1]),(ll)(n-1));
        ll ans=0;
        if(D>=2&&2*D<=n)ans=n-(2*D)+1;
        printf("%lld\n",ans);
        return;
    }
    ll ans=0;
    solve(a,ansa);
    solve(b,ansb);
    for(int k=2;k<=n-2;++k){
        ans=(ans+ansa[k]*ansb[n-(k+1)+1]);
    }
    printf("%lld\n",ans);
}
}
bool ed_M;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T=1;cin>>ZZOI::C>>T;
    while(T--)ZZOI::main();
    // cerr<<(double)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    // cerr<<(&ed_M-&bg_M)/1024.0/1024<<" Mb"<<endl;
    return 0;
}