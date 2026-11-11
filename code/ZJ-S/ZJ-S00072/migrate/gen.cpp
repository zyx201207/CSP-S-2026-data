#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N=1e5+5;
mt19937_64 f(chrono::steady_clock::now().time_since_epoch().count());
ll rd(ll l,ll r){return f()%(r-l+1)+l;}
int a[N];
void _main(){
    int n=rd(1,10),d=rd(1,30);
    cout<<n<<' '<<d<<'\n';
    int cnt=0;
    for(int i=1;i<=(d*n+1)/2;i++)a[++cnt]=i,a[++cnt]=-i;
    shuffle(a+1,a+((d*n+1)/2)*2+1,f),sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<'\n';
}
signed main(){
    clock_t _st=clock();
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=5;cout<<0<<' '<<t<<'\n';
    while(t--)_main();
    clock_t _ed=clock();
    cerr<<(_ed-_st)*1.0/CLOCKS_PER_SEC<<'\n';
    return 0;
}
/*
g++ gen.cpp -o gen -O2 -std=c++14 -DLOCAL
g++ gen.cpp -o gen -std=c++14 -DLOCAL -fsanitize=address,undefined
g++ gen.cpp -o gen -std=c++14 -DLOCAL -fsanitize=address,undefined -pg
g++ gen.cpp -o gen -std=c++14 -DLOCAL -fsanitize=address,undefined -g
*/