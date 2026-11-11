#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N=5e2+2;
mt19937_64 f(chrono::steady_clock::now().time_since_epoch().count());
ll rd(ll l,ll r){return f()%(r-l+1)+l;}
int a[N];
vector<int>e[N];
void _main(){
    int c=0,n=rd(1,250),m=rd(1,250),d=20,q=rd(1,1e5);
    cout<<c<<' '<<n<<' '<<m<<' '<<d<<' '<<q<<'\n';
    for(int i=1;i<=m;i++)cout<<rd(1,1e9)<<' ';cout<<'\n';
    for(int i=1;i<=n;i++)a[i]=i;
    for(int i=1;i<=m;i++){
        int k=rd(1,d);
        shuffle(a+1,a+n+1,f);
        for(int j=1;j<=k;j++)e[a[j]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        cout<<e[i].size()<<' ';
        for(int x:e[i])cout<<x<<' '<<rd(1,1e9)<<' ';cout<<'\n';
    }
    for(int i=1;i<=q;i++)cout<<rd(1,m)<<' '<<rd(1,m)<<'\n';
}
signed main(){
    clock_t _st=clock();
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
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