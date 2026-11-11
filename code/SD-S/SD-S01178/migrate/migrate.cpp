#include <bits/stdc++.h>
using namespace std;

//istream &fin=cin;
//ostream &fout=cout;
ifstream fin("migrate.in");
ofstream fout("migrate.out");
#ifdef LOCAL
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...)
#endif

using u8=unsigned char;
using u32=unsigned;
using i32=int;
using u64=unsigned long long;
using i64=long long;

#define FOR(i,a,b) for(u32 i=a;i<=(b);i++)
#define REP(i,a,b) for(u32 i=a;i<(b);i++)
#define RFOR(i,a,b) for(u32 i=(a)+1;i-->b;)

template<typename T,typename U=T>
bool ckmin(T&a,U&&b){
    return b<a&&(a=forward<U>(b),true);
}

constexpr u32 kN=2'000'005;
u32 c,t,n;
u64 d,x[kN];
i64 x0[kN];
u32 nx[kN];
u64 ans;

namespace solution1{
    void solve(){
        u64 cnt=d/(x[2]-x[1]);
        if(cnt<=1){
            fout<<"0\n";
            return;
        }
        if(cnt*2>n){
            fout<<"0\n";
            return;
        }
        fout<<n-(cnt*2-1)<<"\n";
    }
}
void test_case(){
    fin>>n>>d;
    FOR(i,1,n){
        fin>>x0[i];
    }
    {
        i64 delta=*min_element(x0+1,x0+n+1);
        FOR(i,1,n){
            x[i]=x0[i]-delta;
        }
    }
    ans=0;
    if(c==11||c==12){
        solution1::solve();
        return;
    }
    for(u32 l=1,r=1;l<=n;l++){
        if(r<l){
            r=l;
        }
        while(r<n&&x[r+1]-x[l]<=d){
            ++r;
        }
        nx[l]=r;
    }
    RFOR(l,n-1,1){
        u32 r=l;
        bool has_2=false;
        while(true){
            if(nx[r]==r){
                break;
            }
            r=nx[r];
            if(!has_2){
                if(nx[r-2]>=r){
                    ans+=nx[r-1]-nx[r-2];
                }
            }else{
                ans+=nx[r]-nx[r-1];
            }
            if(nx[r-1]==nx[r]){
                if(has_2||nx[r-2]==nx[r]){
                    break;
                }
                has_2=true;
            }
        }
    }
    fout<<ans<<"\n";
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    fin>>c>>t;
    while(t--){
        test_case();
    }
}
