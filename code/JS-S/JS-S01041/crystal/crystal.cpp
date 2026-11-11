#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 5e5 + 5;
int n;
long long m;
long long a[MAXN], pre[MAXN];
bool check(int x){
    long long minn = 1e18;
    for (int i = 1;i + x - 1 <= n;i++){
        minn = min(minn, x * a[i + x - 1] - (pre[i + x - 1] - pre[i - 1]));
    }
    return (minn <= m);
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for (int i = 1;i <= n;i++){
        pre[i] = pre[i - 1] + a[i];
    }
    int l = 1, r = n, ans;
    while (l <= r){
        int mid = l + r >> 1;
        if (check(mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << ans;
}
