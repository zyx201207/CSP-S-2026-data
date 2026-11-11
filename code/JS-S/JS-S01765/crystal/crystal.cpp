#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n, k, a[N], b[N];
bool check(int x){
    int mn=3e18;
    for(int i=x-1;i<=n;i++) mn=min(mn, a[i]*x-(b[i]-b[i-x]));
    return mn<=k;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1, a+1+n);
    for(int i=1;i<=n;i++) b[i]=a[i]+b[i-1];
    int l=1, r=n+1;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout << l;
    return 0;
}
