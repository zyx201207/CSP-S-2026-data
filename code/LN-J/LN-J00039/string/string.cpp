#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int nums[n + 2] = {}, sum = 0;;
    char chars[n + 2] = {};
    for(int i = 1;i <= n;i++){
        cin >> nums[i] >> chars[i];
        sum += nums[i];
    }

    int l = 1, r = n;
    int cnt = 0;
    for(int i = 0, j = sum;i < sum / 2;){
        if(nums[l] == 0){
            l++;
        }
        if(nums[r] == 0){
            r--;
        }

        int minus = min(nums[l], nums[r]);
        if(chars[l] != chars[r]){
            cnt += minus;
        }

        nums[l] -= minus;
        nums[r] -= minus;

        i += minus;
        j -= minus;
    }

    cout << cnt;

    return 0;
}
