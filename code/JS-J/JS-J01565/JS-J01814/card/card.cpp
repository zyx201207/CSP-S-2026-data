#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n;
int m;
int a[N];
int cnt[N];
bool vis[N];
vector<int> v;
bool at(int x) {
    for (int i : v)
        if (i == x)
            return 1;
    return 0;
}
signed main(){
    //freopen("card.in", "r", stdin);
    //freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++){
        v.clear();
        for (int j = i; j <= n; i++){
            if (at(a[j])){
                while (v.back() != a[j])
                    v.pop_back();
                v.pop_back();
                continue;
            }
            v.push_back(a[j]);
        }
        for (int j : v){
            cnt[j]++;
        }
    }
    for (int i = 1; i <= m; i++)
        cout << cnt[i] << ' ';
    return 0;
}
