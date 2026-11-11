#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
ll a[N], cf[N], sum, m;
int n, l=1, r, ans;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+1+n);
    for(int i = 2; i <= n; i++) cf[i] = a[i] - a[i-1];
    while((++r) <= n){
        sum += (r-l+1)*cf[r];
        while(sum > m){
            sum-=(a[r]-a[l]);
            l++;
        }
        ans = max(ans, r-l+1);
    }
    cout << ans+1;
    return 0;
}
