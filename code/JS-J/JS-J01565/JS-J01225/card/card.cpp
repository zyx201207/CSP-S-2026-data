#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
const ll INF = 0x3f;
#define endl '\n'
const int N = 5e5+5;
ll a[N], c[N], stk[N];
int sz;
unordered_map<int, int> mp;
signed main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        unordered_map<int, int> t;
        swap(t, mp);
        sz = 0;
        for(int j = i; j <= n; j++){
            if(mp.count(a[j])){
                sz = mp[a[j]]-1;
            }
            stk[++sz] = a[j];
            mp[a[j]] = sz;
            for(int k = 1; k <= sz; k++){
                cout << stk[k] << " - ";
            }
            cout << endl;
        }
        for(int j = 1; j <= sz; j++){
            c[stk[j]]++;
        }
        cout << "------------\n";
    }
    for(int j = 1; j <= m; j++){
        printf("%lld ", c[j]);
    }
    return 0;
}
