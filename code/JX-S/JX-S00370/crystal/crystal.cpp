#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n,m,ans,a[N];
bool f;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1,greater<int>());
    int p = a[1] - a[2];
    for(int i = 2;i < n;i++){
        if(a[i] - a[i + 1] != p){
            f = true;
        }
    }
    if(!f){
        for(int i = 1;i <= n;i++){
            ans += p * i;
            if(ans == m){
                cout << i + 1 << endl;
                return 0;
            }
            if(ans > m){
                cout << i << endl;
                return 0;
            }
        }
    }
    for(int k = 1;k <= n;k++){
        int sum = 0;
        for(int i = k + 1;i <= n;i++){
            sum += abs(a[k] - a[i]);
            if(sum == m){
                ans = max(ans,i - k + 1);
                break;
            }
            if(sum > m){
                ans = max(ans,i - k);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
