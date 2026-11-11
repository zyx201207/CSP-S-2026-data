#include <bits/stdc++.h>
using namespace std;
int a[500005];
int s[500005];
#define int long long
signed main(){
    int n,m;
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for(int i=1;i<=n;i++){
        s[i] = s[i-1] + a[i];
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=ans+i;j<=n;j++){
            int need = (j-i+1)*a[j] - (s[j] - s[i-1]);
            if(need<=m){
                ans = j-i+1;
            }
            else{
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
