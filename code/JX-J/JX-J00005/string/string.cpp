#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
const int maxa = 1e9 + 10;
int n;
int a[N];
char c[N];
ll ans, llen, rlen;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        //cerr << c[i] << '\n';
    }
    for(int l = 1, r = n; l < r; l++){
        llen += a[l];
        while(true){
            if(rlen + a[r] < llen){
                if(c[l] != c[r]) ans += a[r];
                rlen += a[r];
                r--;
            }else{
                if(c[l] != c[r]){
                    ans += llen - rlen;
                }
                a[r] -= llen - rlen;
                rlen = llen;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}


