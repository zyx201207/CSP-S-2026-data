#include <bits/stdc++.h>
using namespace std;
long long n, m,ans;
long long a[500005];
long long s1[500005],s2[500005];
bool check(long long x){
    if(s2[1] - s2[x]-s1[x]*(x-1) <= m)
        return true;
    else
        return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (long long i = 1; i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1;i--){
        s1[i] = s1[i + 1] + a[i + 1] - a[i];
        s2[i] = s2[i + 1] + s1[i];
    }
    
    long long l = 1, r = n, mid,ll=l,lr=r;
    while(l < r){
        mid = (l + r) / 2;
        if(check(mid)){
            l = mid;
        }else{
            r = mid - 1;
        }
        if(ll==l&&lr==r)
            break;
        ll = l, lr = r;
    }
    cout << l;
    /*
    for (long long i = 1; i <= n;i++){
        if(s2[1] - s2[i]-s1[i]*(i-1) <= m)
            ans = i;
        else
            break;
    }
    cout << ans;
    */
    return 0;
}