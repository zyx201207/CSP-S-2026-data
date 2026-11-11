#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[5*(int)1e5+5],s[5*(int)1e5+5];
bool check(int x){
    for(int i = x;i<=n;i++){
        if(m>=a[i]*x-s[i]+s[i-x]) return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i<=n;i++) cin >> a[i];
    sort(a+1,a+1+n);
    for(int i = 1;i<=n;i++) s[i]=s[i-1]+a[i];
    int l = 1;
    int r = n;
    int ans = 1;
    while(l<=r){
        int mid = l+r>>1;
        if(check(mid)){
            l = mid+1;
            ans = mid;
        }
        else{
            r = mid-1;
        }
    }
    cout << ans << '\n';
    return 0;
}
