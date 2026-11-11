#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 2e5 + 5;
int n, m;
int a[N];
int ans;

void solve(vector<int>& v, int u){
    if (u < 0) return;
    vector<int> cnt;
    for (int x : v){
        if ((a[x] & (1 << u)) != 0){
            cnt.push_back(x);
        }
    }
    if (cnt.size() >= m){
        ans += (1 << u);
        solve(cnt, u-1);
    }
    else{
        solve(v, u-1);
    }
    return;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    vector<int> v;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        v.push_back(i);
    }
    solve(v, 30);

    cout << ans;

    return 0;
}
