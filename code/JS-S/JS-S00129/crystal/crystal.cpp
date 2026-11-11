#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000001], b[10000001];
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    int l = 1, r = 1, ans = 0, cnt = 0;
    while(l<=r && r<=n){
        if(cnt<=m){
            ans = max(r-l+1, ans);
            cnt+=(a[r]-a[r-1])*(r-l);
            r++;
        }else{
            cnt-=a[l+1]-a[l];
            l++;
        }
    }
    cout << ans-1;
    return 0;
}