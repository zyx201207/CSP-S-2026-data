#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
long long n;
long long m,ans,a[N],sum[N];
unsigned long long tot;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n >>m;
    for (int i = 1;i <= n;i++)
        cin >>a[i];
    sort(a +1,a + n +1);
    bool flag1 = true,flag2 = true;
    for (int i = 2;i <= n;i++){
        sum[i] = a[i] - a[i-1];
        if (sum[i] != sum[i-1] && i >=3) flag1 = false;
        if (a[i] != i) flag2 = false;
    }
    sum[1] = 0;
    if (flag2){
        long long l = 1,r = 1e9;
        while (l <= r){
            long long mid = (l +r)/2;
            if (mid > (m/(mid +1) * 2)){
                ans = mid;
                r = mid-1;
            }
            else l = mid + 1;
        }
        cout << ans;
        return 0;
    }
    if (flag1){
        long long d = sum[2];
        long long k = m/d * 2;
        long long l = 1,r = 1e9;
        while (l <= r){
            long long mid = (l +r)/2;
            if (mid > (k/(mid +1))){
                ans = mid;
                r = mid-1;
            }
            else l = mid + 1;
        }
        cout << ans;
        return 0;
    }
    for (long long i = 1;i <= n;i++){
        tot = 0;
        for (long long j = i;j <= n;j++){
            tot += (j-i) * sum[j];
            if (tot > m){
                ans = max(ans,j-i);
                break;
            }
        }
        if ((n-i+1) < ans) {
            cout << ans;
            return 0;
        }
    }
    cout << ans;
    return 0;
}
