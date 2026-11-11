#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
long long n,m;
long long a[N],f[3][N],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        f[1][i] = a[i];
    }
    if(m == 1){
        for(int i = 1;i <= n;i++) ans = max(ans,a[i]);
        cout << ans;
        return 0;
    }
    if(m == n){
        ans = a[1];
        for(int i = 2;i <= n;i++) ans&=a[i];
        cout << ans;
        return 0;
    }
    if(m == n-1){
        ans = a[1];
        long long ans2 = 0;
        for(int i = 2;i <= n;i++){
            ans = a[1];
            for(int j = 1;j <=n;j++){
                if(i==j) continue;
                ans&=a[j];
            }
            ans2=max(ans,ans2);
        }

        cout << ans2;
        return 0;
    }
    if(m == 2){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i==j) continue;
            f[2][i] = max(f[2][i],a[i]&a[j]);
            ans = max(ans,f[2][i]);
        }
    }
    cout << ans;
    return 0;
    }
    cout << 0;

    return 0;
}
