#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
ll a[N], c[N], t1[N];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    bool flag = 1;
    for(int i = 2; i <= n; i++){
        if(a[i] < a[i - 1]){
            flag = 0;
            break;
        }
    }
    if(flag){
        for(int i = 1; i <= n; i++) c[a[i]]++;
        for(int i = 1; i <= m; i++) cout << c[i] << " ";
    }else{
        vector <ll> b;
        for(int i = 1; i <= n; i++){
            ll t[m + 10] = {0};
            for(int j = i; j <= n; j++){
                if(a[j] == a[j - 1] && j != i) continue;
                t[a[j]]++;
                if(t[a[j]] > 1){
                    t[a[j]] = 1;
                    while(b.size() > 1 && b.back() != a[j]){
                        t[b.back()]--;
                        b.pop_back();
                    }
                }else b.push_back(a[j]);
            }
            while(b.size()){
                c[b.back()]++;
                b.pop_back();
            }
        }
        for(int i = 1; i <= m; i++) cout << c[i] << " ";
    }
    return 0;
}
