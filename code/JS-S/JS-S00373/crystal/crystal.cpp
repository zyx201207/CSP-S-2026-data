// first op, finally merge !
// USE LONG LONG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
int n;
ll m;
const int N = 5e5+5;
ll a[N];
bool check(int x) {
    if(x==1) return true;
    //1. sort
    //2. find min cost 
    //window
    ll sum=0;
    for(int i=1;i<=n;i++) {
        if(i>=x) {
            if(a[i]*(x-1)-sum <= m)
                return true; 
        }
        sum += a[i];
        if(i>=x) sum-=a[i-x+1];
    }
    return false;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1, a+n+1);
    int l=1, r=n;
    while(l<r) {
        int mid= (l+r)/2;
        if(l==mid) mid++;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<'\n';
    return 0;
}