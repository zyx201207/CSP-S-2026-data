#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N=5e5+5;
int n;
ll m,a[N],s[N];
ll w(int l,int r){return a[r]*(r-l+1)-(s[r]-s[l-1]);}
void _main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=i,r=n+1;
        while(l<r){
            const int mid=l+r>>1;
            if(w(i,mid)<=m)l=mid+1;
            else r=mid;
        }
        // cout<<i<<' '<<r-1<<' '<<w(i,r-1)<<'\n';
        ans=max(ans,r-i);
    }
    cout<<ans<<'\n';
}
signed main(){
    clock_t _st=clock();
#ifndef LOCAL
    freopen("crystal.in","r",stdin);
    freopen("crtstal.out","w",stdout);
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
g++ crystal.cpp -o crystal -O2 -std=c++14 -DLOCAL -Wall -Wextra
g++ crystal.cpp -o crystal -std=c++14 -DLOCAL -fsanitize=address,undefined -Wall -Wextra
g++ crystal.cpp -o crystal -std=c++14 -DLOCAL -fsanitize=address,undefined -pg -Wall -Wextra
g++ crystal.cpp -o crystal -std=c++14 -DLOCAL -fsanitize=address,undefined -g -Wall -Wextra
*/