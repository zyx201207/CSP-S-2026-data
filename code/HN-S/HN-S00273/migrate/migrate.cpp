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
int n,nxt[maxn],lst[maxn],t[maxn];
ll k,a[maxn],f[maxn],g[maxn],res;
vector<int> v1[maxn],v2[maxn];
void solve(){
    n=read<int>(),k=read<ll>(),res=0;
    for(int i=1;i<=n;i++) a[i]=read<ll>(),f[i]=g[i]=0;
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
    z=n;
    for(int i=1;i<=n;i++) t[i]=0;
    for(int i=n;i;i--){
        while(z>nxt[i]) t[lst[z]]--,z--;
        f[i]=t[i];
        if(i!=nxt[i]) f[i]+=(lst[nxt[i]]==i)*(f[nxt[i]]);
        t[lst[i]]++;
    }
    for(int i=1;i<=n;i++) t[i]=0;
    z=1;
    for(int i=1;i<=n;i++){
        while(z<lst[i]) t[nxt[z]]--,z++;
        g[i]=t[i];
        if(i!=lst[i]) g[i]+=(nxt[lst[i]]==i)*(g[lst[i]]);
        t[nxt[i]]++;
    }
    for(int i=1;i<=n;i++){
        int j=nxt[nxt[i]];
        if(j<=nxt[i]||i>=lst[j]||nxt[i]-lst[j]!=1||nxt[nxt[i]]==nxt[i]||lst[lst[j]]==lst[j]) continue;
        if(nxt[nxt[i]]==j&&lst[lst[j]]==i) res=res+g[i]*f[j];
        if(nxt[nxt[i]]==j&&lst[lst[j]]<=i) res+=f[j];
    }
    for(int j=1;j<=n;j++){
        int i=lst[lst[j]];
        if(j<=nxt[i]||i>=lst[j]||nxt[i]-lst[j]!=1||nxt[nxt[i]]==nxt[i]||lst[lst[j]]==lst[j]) continue;
        if(nxt[nxt[i]]>=j&&lst[lst[j]]==i) res+=g[i];
    }
    for(int i=1;i<=n;i++) if(nxt[nxt[i]]!=nxt[i]&&i<nxt[i]-1) v1[nxt[i]].pb(i);
    for(int i=1;i<=n;i++) if(lst[lst[i]]!=lst[i]&&i>lst[i]+1) v2[lst[i]].pb(i);
    for(int i=2;i<=n;i++){
        int c1=0,c2=0;
        for(int x:v1[i]) c1+=(lst[i-1]<=x);
        for(int x:v2[i-1]) c2+=(nxt[i]>=x);
        res+=1ll*c1*c2;
    }
    print(res,'\n');
    for(int i=1;i<=n;i++) v1[i].clear(),v2[i].clear();
}
int main(){
    FileIO("migrate");
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    read<int>(),t=read<int>();
    while(t--) solve();
    return 0;
}
/*
孙奕东，后面忘了。

大苹果吧我爱你。
*/