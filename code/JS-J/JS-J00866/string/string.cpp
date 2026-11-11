#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

struct str{
    ll x; char c;
} a[N], b[N];
ll n, m, i1, j, i2, cnt, ans;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].c;
        b[i] = a[i], m += a[i].x;
    }
    reverse(b+1, b+n+1);
    cout << m << endl;
    i1 = 1, i2 = 1;
    for( ; i1 <= n; i1++){
        int del = a[i1].x;
        if(cnt + a[i1].x > m/2)
            del = m/2 - cnt;
        cnt += del;
        while(del){
            if(del < b[i2].x - j){
                if(b[i2].c != a[i1].c) ans += del;
                j += del, del = 0;
            } else{
                if(b[i2].c != a[i1].c) ans += (b[i2].x-j);
                del -= (b[i2].x-j), i2++, j=0;
            }
        }
        if(cnt == m/2) break;
    }
    cout << ans << endl;
}
