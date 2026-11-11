#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
using LL = long long;

struct point {
    int num;
    char ch;
}a[N];

int n;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    LL suma = 0;

    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i].num >> a[i].ch;
        suma += a[i].num;
    }

    LL halfn = suma/2;
    LL l = 1, r = n, cntl = 0, cntr = 0;
    LL ans = 0;

    while(l <= r){
        if(l >= r || cntl > halfn || cntr > halfn)break;
        if(a[l].num < a[r].num){
            cntl += a[l].num;
            cntr += a[l].num;

            a[r].num -= a[l].num;

            if(a[l].ch != a[r].ch)ans += a[l].num;
            
            l ++;
        }else if(a[l].num > a[r].num){
            cntl += a[r].num;
            cntr += a[r].num;

            a[l].num -= a[r].num;

            if(a[l].ch != a[r].ch)ans += a[r].num;
            
            r --;
        }else if(a[l].num == a[r].num){
            cntl += a[l].num;
            cntr += a[r].num;

            if(a[l].ch != a[r].ch)ans += a[l].num;

            l ++;
            r --;
        }
    }
    cout << ans << '\n';
    return 0;
}