#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll INF = 0x3f;
#define endl '\n'
const int N = 2e5+5;
ll a[N];
char ch[N];
int n, p, q, lt, rt;
int rv(int x){
    return n-x+1;
}
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> ch[i];
        rt += a[i];
    }
    p = 1, q = n, lt = 1;
    ll ans = 0;
    while(p < q){
        int lr = lt+a[p]-1, rl = rt-a[p]+1;
        if(ch[p] != ch[q]){
            ans += min(a[p], a[q]);
        }
        if(a[p] > a[q]){
            a[p] -= a[q];
            q--;
        }else{
            a[q] -= a[p];
            p++;
        }
    }
    cout << ans << endl;
    return 0;
}
