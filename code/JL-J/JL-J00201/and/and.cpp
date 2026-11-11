#include <bits/stdc++.h>
using namespace std;
int n, m, a[200001];
vector<int> t[32];
bool check(int x, int k){
    return (x >> (k - 1)) & 1;
}
void solve(int x){
    int ans = 1 << (x - 1), fr = x;
    for (int i = x - 1; i >= 1; i--){
        for (int j = 0; j < t[fr].size(); j++)
            if (check(t[fr][j], i))
                t[i].push_back(t[fr][j]);
        if (t[i].size() >= m){
            ans += 1 << (i - 1);
            fr = i;
        }
    }
    cout << ans;
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 31; i >= 1; i--){
        for (int j = 1; j <= n; j++)
            if (check(a[j], i)) {
                t[i].push_back(a[j]);
            }
        if (t[i].size() >= m){
            solve(i);
            return 0;
        }
    }
    cout << 0;
    return 0;
}
