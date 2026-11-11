#include <bits/stdc++.h>
using namespace std;

//istream &fin=cin;
//ostream &fout=cout;
ifstream fin("crystal.in");
ofstream fout("crystal.out");
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

constexpr u32 kN=500'005;
u32 n;
i64 m;
i64 a[kN],sum[kN];

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    fin>>n>>m;
    FOR(i,1,n){
        fin>>a[i];
    }
    sort(a+1,a+n+1);
    u32 l=0,ans=0;
    FOR(i,1,n){
        sum[i]=sum[i-1]+a[i];
        while(l<n&&a[i]*(i-l)-(sum[i]-sum[l])>m){
            l++;
        }
        ans=max(ans,i-l);
    }
    fout<<ans<<"\n";
}
