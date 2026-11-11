#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N=5e5+5;
int n;
ll m,a[N];
void _main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            ll s=0;
            for(int k=j;k<=i;k++)s+=a[i]-a[k];
            if(s<=m)ans=max(ans,i-j+1);
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    clock_t _st=clock();
#ifndef LOCAL
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    while(t--)_main();
    clock_t _ed=clock();
    cerr<<(_ed-_st)*1.0/CLOCKS_PER_SEC<<'\n';
    return 0;
}
/*
g++ std.cpp -o std -O2 -std=c++14 -DLOCAL -Wall -Wextra
g++ std.cpp -o std -std=c++14 -DLOCAL -fsanitize=address,undefined -Wall -Wextra
g++ std.cpp -o std -std=c++14 -DLOCAL -fsanitize=address,undefined -pg -Wall -Wextra
g++ std.cpp -o std -std=c++14 -DLOCAL -fsanitize=address,undefined -g -Wall -Wextra
*/