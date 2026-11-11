#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N],mx;
signed main() {
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++) {
        int b=i;
        for(int S=1<<20;S;S>>=1) {
            int t=b-S;
            if(t<1) continue;
            if(a[i]*(i-t+1)-(s[i]-s[t-1])<=m) b=t;
        }
        mx=max(mx,i-b+1);
    }
    cout<<mx<<'\n';
}
//while true; do ./Gen.exe > check.in; ./Cmp.exe < check.in > check.ans; ./crystal.exe < check.in > check.out; diff -q check.out check.ans || { echo"WA"; break; }; done