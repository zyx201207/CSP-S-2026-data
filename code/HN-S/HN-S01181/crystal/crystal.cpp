#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 10;

int n;
ll m, a[N];

namespace subtask1{
    int ans;

    void solve(){
        ans = 0;
        for(int i = -100; i <= 100; i++){
            int x = upper_bound(a + 1, a + n + 1, i) - a - 1;
            ll t = m;
            int sum = 0;
            for(int j = x; j >= 1; j--){
                if(t >= i - a[j]){
                    t -= (i - a[j]);
                    sum++;
                } else{
                    break;
                }
            }
            ans = max(ans, sum);
        }
        cout << ans;
    }
}

namespace special_A{
    int ans;

    void solve(){
        ll t = m, x = 1;
        while(1){
            if(t - x < 0) break;
            t -= x;
            x++;
        }
        ans = x;
        cout << ans;
    }
}

namespace special_B{
    int ans;

    void solve(){
        ll t = m, x = 1;
        while(1){
            if(t - 1ll * x * (a[2] - a[1]) < 0) break;
            t -= 1ll * x * (a[2] - a[1]);
            x++;
        }
        ans = x;
        cout << ans;
    }
}

namespace subtask_m_0{
    int ans;

    void solve(){
        ans = 0;
        int sum = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] == a[i - 1]){
                sum++;
            } else{
                ans = max(ans, sum);
                sum = 1;
            }
        }
        cout << ans;
    }
}

namespace subtask{
    priority_queue<int, vector<int>, greater<int>> pq;

    void solve(){

    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crtstal.out", "w", stdout);
    cin >> n >> m;
    bool sub1 = true, sp_A = true, sp_B = true;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(abs(a[i]) > 100) sub1 = false;
        if(a[i] != i) sp_A = false;
    }
    for(int i = 3; i <= n; i++){
        if(a[i] - a[i - 1] != a[i - 1] - a[i - 2]) sp_B = false;
    }
    sort(a + 1, a + n + 1);
    if(sub1 == true){
        subtask1::solve();
    } else if(sp_A == true){
        special_A::solve();
    } else if(sp_B == true){
        special_B::solve();
    } else if(!m){
        subtask_m_0::solve();
    }
    return 0;
}
