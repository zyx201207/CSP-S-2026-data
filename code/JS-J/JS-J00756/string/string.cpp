#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 1; i <= n; i++)
using namespace std;
const int N = 2e5 + 10;
int n;
int a[N];
char c[N];
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n){
        cin >> a[i] >> c[i];
    }
    int l(1), r(n), nl = a[1], nr = a[n], cnt(0);
    while(l < r){
        if(c[l] != c[r]){
            cnt += min(nl, nr);
        }
        if(nl < nr){
            nr -= nl;
            l++;
            nl = a[l];
        }
        else if(nr < nl){
            nl -= nr;
            r--;
            nr = a[r];
        }
        else{
            l++; r--;
            nl = a[l];
            nr = a[r];
        }
    }
    cout << cnt;
    return 0;
}
