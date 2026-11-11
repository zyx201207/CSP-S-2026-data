#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 5e5 + 7;
int n, m, a[N], t[N];
bool flag = true;
signed main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] < a[i - 1]) flag = false;
        t[a[i]]++;
    }
    if(flag){
        for(int i = 1; i <= n; i++){
            cout << t[i] << '\n';
        }
    }
    for(int i = 1; i <= n; i++){
        cout << i << '\n';
    }
    return 0;
}