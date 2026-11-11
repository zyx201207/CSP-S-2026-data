#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define fi first
#define sc second
#define pii pair<int,int>
#define pdd pair<double,double>
#define pb push_back
#define umap unordered_map
#define pq priority_queue
#define mset multiset
#define ull unsigned long long
#define i128 __int128
#define fixs fixed<<setprecision
#define FileIn(x) freopen(x".in","r",stdin)
#define FileOut(x) freopen(x".out","w",stdout)
#define FileIO(x) FileIn(x),FileOut(x)
namespace FastIO{
    char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p1=buf,p2=(p1+fread(buf,1,1<<21,stdin)))==p1?EOF:*p1++)
    template<typename T>inline T read(){T x=0,w=0;char ch=getchar();while(ch<'0'||ch>'9') w|=(ch=='-'),ch=getchar();while('0'<=ch&&ch<='9') x=x*10+(ch^'0'),ch=getchar();return w?-x:x;}
    template<typename T>inline void write(T x){if(!x) return ;write(x/10),putchar((x%10)^'0');}
    template<typename T>inline void print(T x){if(x<0) putchar('-'),write(-x);else if(x>0) write(x);else putchar('0');}
    template<typename T>inline void print(T x,char en){print(x),putchar(en);}
}using namespace FastIO;
const int maxn=2e6+10;
int n,nxt[maxn],lst[maxn];
ll k,a[maxn];
bool chk(int x,int y){
    ll sum=y-x;
    int now=x;
    while(now<y){
        if(now==nxt[now]) return 0;
        sum+=now,now=nxt[now];
    }
    now=y;
    while(now>x){
        if(now==lst[now]) return 0;
        sum-=now,now=lst[now];
    }
    // cerr<<x<<" "<<y<<" "<<sum<<endl;
    // if(sum==1) cerr<<x<<" "<<y<<endl;
    return (sum==1);
}
void solve(){
    n=read<int>(),k=read<ll>();
    for(int i=1;i<=n;i++) a[i]=read<ll>();
    int z=1;
    for(int i=1;i<=n;i++){
        while(z<=n&&a[z]-a[i]<=k) z++;
        nxt[i]=z-1;
    }
    z=n;
    for(int i=n;i;i--){
        while(z>=1&&a[i]-a[z]<=k) z--;
        lst[i]=z+1;
    }
    // for(int i=1;i<=n;i++) cerr<<nxt[i]<<" ";cerr<<endl;
    // for(int i=1;i<=n;i++) cerr<<lst[i]<<" ";cerr<<endl;
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++) res+=chk(i,j);
    }
    print(res,'\n');
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    read<int>(),t=read<int>();
    while(t--) solve();
    return 0;
}