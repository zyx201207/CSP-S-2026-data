#include <bits/stdc++.h>

using namespace std;

long long n, m;
vector<long long> a;
vector<long long> dp;
bool flag;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    int _;
    cin >> _;
    a.push_back(_);
    cin >> _;
    a.push_back(_);
    for(int i = 2; i < n; i++) {
        cin >> _;
        a.push_back(_);
        if(a[i] - a[i-1] != a[i-1] - a[i-2]) {
            flag = true;
        }
    }
    if(flag) {
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++) {
            int k = m;
            for(int j = i - 1; ; j--){
                if(j >= 0){
                    k -= a[i] - a[j];
                    if(k < 0) {
                        dp.push_back(i-j);
                        break;
                    }
                } else {
                    dp.push_back(i+1);
                    break;
                }
            }
        }
        sort(dp.begin(), dp.end());
        cout << dp[dp.size()-1];
    } else {
        int y = a[1] - a[0];
        cout << min((long long)n, (long long)(ceil((sqrt(1+8.0*double(m)/double(y))-1)/2)));
    }
    return 0;
}
