#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,l,r) for(int i=l;i<=r;++i)
#define F_(i,r,l) for(int i=r;i>=l;i--)
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define gc getchar
#define pc putchar
#define mid ((l+r)>>1)
#define ull unsigned long long
#define SZ(a) ((int)(a).size())
#define pb push_back
#define cint const int

cint mod = 998244353;
cint INF = 1e18;
cint N = 5e5 + 5;

inline int rd(){
    int x=0,y=1;
    char c=gc();
    for(;!isdigit(c);c=gc()){
        if(c=='-'){
            y=-1;
        }
    }
    for(;isdigit(c);c=gc()){
        x=(x<<3)+(x<<1)+(c^48);
    }
    return x*y;
}

inline void cmx(int &a,int b){
    a=max(a,b);
}

inline void cmn(int &a,int b){
    a=min(a,b);
}

inline void add(int a,int b){
    a+=b;
    if(a>=mod){
        a-=mod;
    }
    if(a<0){
        a+=mod;
    }
}

namespace Day_Tao{
    int n,m,a[N],sm[N];
    inline bool chk(int x,int i){
        int t=sm[i]-sm[x-1];
        if(a[i]*(i-x+1)-t<=m){
            return true;
        }else{
            return false;
        }
    }
    inline void SOLVE(){
        n=rd(),m=rd();
        F(i,1,n){
            a[i]=rd();
        }
        sort(a+1,a+n+1);
        F(i,1,n){
            sm[i]=sm[i-1]+a[i];
        }
        int ans=1;
        F(i,2,n){
            int l=1,r=i-1,p=1;
            while(l<=r){
                if(chk(mid,i)){
                    p=mid,r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            cmx(ans,i-p+1);
        }
        printf("%lld\n",ans);
        return ;
    }
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int T=1;
    // T=rd();
    while(T--){
        Day_Tao::SOLVE();
    }
    return 0;
}

/*
x x xxx
o o ooo
xx x xxx
oo o ooo
lai bu ji le bu xie le
18:28
*/