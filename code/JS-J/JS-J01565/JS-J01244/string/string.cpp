#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

typedef long long ll;

struct p{
    int a;
    char b;
};

p a[N];

int n;
ll sum;

void init(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int x;
        char y;
        cin >> x >> y;
        a[i].a = x;
        a[i].b = y;
        sum += a[i].a;
    }
    return;
}

void solve(){
    ll ans = 0, zhong = (sum + 1) / 2;
    ll q = 0;
    int w = 0;
    ll p = q;
    for(int i = 1; i <= n; ++i){
        p = q;
        q += a[i].a;
        if(q >= zhong){
            w = i;
            break;
        }
    }
    ll le = zhong - p - 1;
    ll ri = q - zhong;
    ll su = ri - le;
    if(su < 0)
        su *= -1;
    if(a[w].a < 0)
        a[w].a *= -1;
    int l = 1, r = n;
    ll ls = 0, rs = 0;
    while(r > w && l < w){
        if(a[l].b != a[r].b){
            if(a[l].a >= a[r].a){
                ans += a[r].a;
                a[l].a -= a[r].a;
                a[r].a = 0;
            } else {
                ans += a[l].a;
                a[r].a -= a[l].a;
                a[l].a = 0;
            }
        }
        else{
            if(a[l].a >= a[r].a){
                a[l].a -= a[r].a;
                a[r].a = 0;
            } else {
                a[r].a -= a[l].a;
                a[l].a = 0;
            }
        }
        if(a[l].a <= 0){
            ++l;
        }
        if(a[r].a <= 0){
            --r;
        }
    }
    cout << ans + su << endl;
    return;
}

int main(){
    init();
    solve();
    return 0;
}
