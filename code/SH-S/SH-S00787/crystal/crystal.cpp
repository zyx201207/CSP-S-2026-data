#include <bits/stdc++.h>
using namespace std;
long long n,m;
const int N = 5e5 + 5;
long long a[N];
long long sum[N];
int ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
    for(int i = 1;i <= n;i++){ //枚举目标能量值
        long long num = a[i];
        //求区间1~i-1最大值
        //于是考虑二分左端点
        int l = 1,r = i - 2;
        while(l <= r){
            int mid = l + r >> 1;
            int cnt = i - mid + 1;
            if (cnt * a[i] - (sum[i] - sum[mid - 1]) <= m) r = mid - 1;
            else l = mid + 1; 
        }
        //l~i
        //cout << l << " " << i << endl;
        ans = max(ans,i - l + 1);
    }
    cout << ans;
    return 0;
}
