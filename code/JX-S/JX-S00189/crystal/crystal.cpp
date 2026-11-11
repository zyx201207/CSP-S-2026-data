#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 10;
int a[N];
int sum[N];
int n, m;
int ans;
bool f = true;
int delta;
bool check(int mid){
    if((1 + mid) * mid / 2 <= m) return true;
    else return false;
}
bool check2(int mid){
    if((delta + delta * mid) * mid / 2 <= m) return true;
    else return false;
}
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] != i) f = false;
    }
    sort(a + 1, a + 1 + n);
    delta = a[2] - a[1];
    bool f1 = true;
    for(int i = 2;i <= n;i++){
        if(a[i] - a[i - 1] != delta){
            f1 = false;
            break;
        }
    }
    if(f){
        /*
        int left = 1, right = n;
        while(left <= right){
            int mid = (left + right) / 2;
            if(check(mid)){
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << ans;*/
        for(int i = n;i >= 1;i--){
            if(check(i)){
                cout << i + 1;
                return 0;
            }
        }
        return 0;
    }
    if(f1){
        for(int i = n;i >= 1;i--){
            if(check2(i)){
                cout << i + 1;
                return 0;
            }
        }
        return 0;
    }
    sort(a + 1, a + 1 + n);
    for(int i = 2;i <= n;i++){
        sum[i] = sum[i - 1] + (a[i] - a[i - 1]);
    }

    for(int i = 1;i <= n;i++){
        int cnt = 1;
        int s = 0;
        for(int j = i - 1;j >= 1;j--){
            if(s + (sum[i] - sum[j]) <= m){
                s += sum[i] - sum[j];
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
    return 0;
}