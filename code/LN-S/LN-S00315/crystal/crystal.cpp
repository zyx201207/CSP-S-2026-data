#include<bits/stdc++.h>
using namespace std;
#define int long long
bool is_A(const vector<int>& a, int n){
    int l = a.size();
    for(int i = 2;i <= n; i++){
        if(a[i] - a[i-1] != 1){
            return false;
        }
    }
    return true;
}
bool is_B(const vector<int>& a, int n){
    int l = a.size();
    int d = a[2] - a[1];
    for(int i = 3;i <= n; i++){
        if(a[i] - a[i-1] != d){
            return false;
        }
    }
    return true;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1;i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    /*
    1.第一层循环先找一遍所谓的基准
    2.基准向左看齐
    3.不断加加加
    4.冒了就打擂台
    */
    if(n <= 5000){
        int ans = LLONG_MIN;
        for(int i = 1;i <= n; i++){
            //目前a[i]是基准
            //向左看
            int cnt = 0, k = 0;
            for(int j = i;j >= 1; j--){
                cnt += a[i] - a[j];
                if(cnt > m){
                    break;
                }
                k++;
            }
            ans = max(ans, k);
        }
        cout << ans;
        return 0;
    }
    if(is_A(a, n) == true){
        //解(1+n)*n = 2*m的n的最大值(但是这个是买来的，自己还得算一个)
        for(int i = 1;i <= 2 * m; i++){
            if(i * (i + 1) > 2 * m){
                cout << i;
                return 0;
            }
        }
    }
    if(is_B(a, n) == true){
        //解(2*a[0]+(n-1)*d) = 2*m的n的最大值
        int d = a[2] - a[1];
        for(int i = 1;i <= 2 * m; i++){
            if((2 * a[1] + (i - 1) * d) * i > 2 * m){
                cout << i;
                return 0;
            }
        }
    }
    return 0;
}
