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
cint N = 2e6 + 5;

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
    int n,d,a[N],ans;
    inline void SOLVE(){
        n=rd(),d=rd();
        F(i,1,n){
            a[i]=rd();
        }
        a[n+1]=0;
        ans=0;
        F(i,1,n){
            int pre=i,cnt=0;
            F(j,i+1,n){
                if(a[j]-a[j-1]>d){
                    break;
                }
                if(j!=n&&a[j+1]-a[pre]>d){
                    if(pre-1>i){
                        if(a[j]-a[pre-1]<=d){
                            ++cnt;
                            if(cnt>1){
                                break;
                            }
                        }
                        if(pre-2>i&&a[j]-a[pre-2]<=d){
                            break;
                        }
                    }
                    if(cnt==1){
                        ++ans;
                    }
                    pre=j;
                }else{
                    int ct=cnt;
                    if(pre-1>i){
                        if(a[j]-a[pre-1]<=d){
                            ++ct;
                            if(ct>1){
                                continue;
                            }
                        }
                        if(pre-2>i&&a[j]-a[pre-2]<=d){
                            continue;
                        }
                    }
                    if(ct==1){
                        ++ans;
                    }
                }
            }
        }
        printf("%lld\n",ans);
        return ;
    }
    inline void SOLVE1(){
        n=rd(),d=rd();
        F(i,1,n){
            a[i]=rd();
        }
        int x=a[2]-a[1];
        if(x>d||d>=a[n]-a[1]||d==x){
            puts("0");
            return ;
        }
        printf("%lld\n",n-(2*(d/x))+1);
    }
    inline void SOLVE2(){
        // n=rd(),d=rd();
        // F(i,1,n){
        //     a[i]=rd();
        // }
        // int p=-1;
        // F(i,1,n){
        //     if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
        //         p=i;
        //         break;
        //     }
        // }
    }
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T=1;
    int c=rd();
    T=rd();
    if(c==11||c==12){
        while(T--){
            Day_Tao::SOLVE1();
        }
        return 0;
    }
    if(c==13||c==14){
        while(T--){
            Day_Tao::SOLVE2();
        }
        return 0;
    }
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