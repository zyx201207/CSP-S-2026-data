#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 514514;
//by 2m OvO!
int a[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;cin >> n;ll m,ans = 0,x = 0;cin >> m;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i = 0;i < n;i++){
        if(m>=(a[i]-x)*ans){
            m -= (a[i]-x)*ans;
            x = a[i];
            ans++;
        }else{
            m += a[i]-x+x-a[i-ans];
        }
    }
    cout << ans;
    return 0;
}
