#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],ans = 1,val = 0,cnt = 0,res = 0,start = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a,a + n);
    val = a[0];
    for (int i = 1;i < n;i++){
        if ((a[i] - val) * ans + cnt < m + 1){
            cnt += (a[i] - val) * ans;
            ans++;
            val = a[i];
        }
        else{
            res = max(res,ans);
            cnt += (a[i] - val) * ans;
            while (cnt > m && start < i + 1){
                cnt -= a[i] - a[start];
                start++;
                ans--;
            }
            if (cnt < m + 1){
                ans++;
                val = a[i];
            }
        }
    }
    res = max(res,ans);
    cout << res;
    return 0;
}
