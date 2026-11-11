#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

const int N = 2e5 + 10;

ll n, m, a[N], ans, b[N];

void dfs(int step, int t)
{
    if(step == m){
        ll res = b[0];
        for(int i = 1;i < m;i++){
            res = (res & b[i]);
        }
        ans = max(ans, res);
        return;
    }
    for(int i = t;i < n;i++){
        b[step] = a[i];
        dfs(step + 1, i + 1);
    }
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);  
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        ans = max(ans, a[i]);
    }
    if(m == 1){
        cout << ans << endl;
    }else if(m == n){
        ans = a[0];
        for(int i = 1;i < n;i++){
            ans = (ans & a[i]);
        }
        cout << ans << endl;
    }else if(m == 2){
        ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                ans = max(ans, (a[i] & a[j]));
            }
        }
        cout << ans << endl;
    }else if(n <= 20){
        ans = 0;
        dfs(0, 0);
        cout << ans << endl;
    }else{
        sort(a, a + n);
        ans = a[n - 1];
        for(int i = 0;i < m - 1;i++){
            ans = (ans & a[i]);
        }
        cout << ans << endl;
    }

    return 0;
}