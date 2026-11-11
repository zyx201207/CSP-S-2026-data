#include <bits/stdc++.h>
using namespace std;
int n,m,ans = 1,a[50005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    for(int i = 2; i <= n;i++){
        int lm = m,ansn = 1;
        for(int j = i - 1;j >= 1;j--){
            if(lm>= a[i] - a[j]){
                lm = lm - a[i] + a[j];
                ansn++;
            }
            else{
                break;
            }
        }
        ans = max(ans,ansn);
    }
    cout << ans;
    return 0;
}