#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=5e5+5;
ll a[N],s[N];

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    ll ansi=0;
    for(int i=1;i<=n;i++) {
        ll ls=s[i-1];
        ll cha=abs(a[i]-ls);
        if(cha<=m) ansi=i;
    }
    cout<<ansi-1;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
