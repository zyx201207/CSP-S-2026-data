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
const int N=5;
const int mod=998244353;
int res=1;
void solve(){
    res=read<int>();
    for(int i=1;i<=N;i++) res=1ll*res*i%mod;
    print(res,'\n');
}
int main(){
    // FileIO("aplusb");
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}