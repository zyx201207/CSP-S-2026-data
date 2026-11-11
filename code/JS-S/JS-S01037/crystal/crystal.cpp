#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long a[N],b[N],v[N],c[N],n,m;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b+1,b+n +1);
    sort(a+1,a+n +1);
    int l = unique(b+1,b+n+1) - b;
    for(int i = 1;i <= n;i ++){
        long long x = lower_bound(b+1,b+l,a[i]) - b;
        v[x] = a[i];a[i] = x;
        // cerr << a[i] << ' ';
    }
    long long ans = 0,tmp = 0;
    int r = 1;
    l = 1;
    for(int i = 1;i <= n;i ++,r++){
        c[i] = c[i-1] + v[a[i]];
        while(l <= r && m < (r-l+1ll)*v[a[i]] - (c[r]-c[l-1])) l++;
        // cerr << i << ' '<<l << ' ' << r << ' ' << (r-l+1)*a[i] - c[i] << endl;
        if(m >= (r-l+1ll)*v[a[i]] - (c[r]-c[l-1])){
            ans = max(ans,r-l+1ll);
        }
        // cerr << ans << endl;
    }
    cout << ans << "\n";
}