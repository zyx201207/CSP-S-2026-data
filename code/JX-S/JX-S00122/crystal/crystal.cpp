/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include <bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
intc N=5e5+10;
int n;
intl m;
intl a[N],sum[N];
signed main () {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    Cios;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    intl maxres=0;
    for (int i=1;i<=n;i++) {
        int l=1,r=i;
        intl res=0;
        while (l<=r) {
            int mid=(l+r)>>1;
            if (a[i]*mid-sum[i]+sum[i-mid]<=m) l=mid+1,res=mid;
            else r=mid-1;
        }
        maxres=max(maxres,res);
    }
    cout<<maxres<<"\n";
    return 0;
}

/*
g++ -g crystal.cpp -o crystal -O2 -std=c++14 -static && echo "finish" && ./crystal && rm crystal
*/