#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

const int N = 5e5 + 10;

ll m, n, a[N], ans;

bool f = 1;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    ll res = a[2] - a[1];
    for(int i = 2;i <= n;i++){
        if(a[i] - a[i - 1] != res){
            f = 0;
            break;
        }
    }
    if(f){
        if(n % 2 == 1){
            for(int i = n / 2, j = n / 2 + 2;i >= 1 && m > 0;i--, j++){
                ans++;
                m -= a[n / 2 + 1] - a[i];
                if(m > 0){
                    m -= a[n / 2 + 1] - a[i];
                    ans++;
                }
            }
            cout << ans + 1 - (m < 0) << endl;
        }else{
            for(int i = n / 2 - 1, j = n / 2 + 1;i >= 1 && m > 0;i--, j++){
                ans++;
                m -= a[n / 2] - a[i];
                if(m > 0){
                    m -= a[n / 2] - a[i];
                    ans++;
                }
            }
            if(a[n] - a[n / 2] <= m){
                ans++;
                m -= a[n] - a[n / 2];
            }
            cout << ans + 1 - (m < 0) << endl;
        }
    }else{
        for(int i = 2;i < n;i++){
            ll t = m, sum = 0;
            for(int j = i - 1, k = i + 1;(j >= 1 || k <= n) && t > 0;){
                if(j < 1){
                    sum++;
                    t -= llabs(a[k] - a[i]);
                    k++;
                    continue;
                }else if(k > n){
                    sum++;
                    t -= llabs(a[i] - a[j]);
                    j--;
                    continue;
                }
                if(llabs(a[i] - a[j]) > llabs(a[k] - a[i])){
                    sum++;
                    t -= llabs(a[k] - a[i]);
                    k++;
                }else{
                    sum++;
                    t -= llabs(a[i] - a[j]);
                    j--;
                }
            }
            ans = max(sum + 1 - (t < 0), ans);
        }
        cout << ans << endl;
    }

    return 0;
}