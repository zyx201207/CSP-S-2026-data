#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int c1, s1, c2, s2;
    char t1, t2;
    cin >> c1 >> s1 >> t1 >> c2 >> s2 >> t2;
    //cout << c1 << s1 << t1 << c2 << s2 << t2;
    if(c1 != c2){
        puts("0000");
        return;
    }
    putchar('1');
    if(s1 != s2){
        puts("000");
        return;
    }
    putchar('1');
    if(!((t1 == 'A' && t2 == 'B') || (t1 == 'A' && t2 == 'C') || (t1 == 'B' && t2 == 'A') || (t1 == 'B' && t2 == 'C') ||
       (t1 == 'C' && t2 == 'A') || (t1 == 'C' && t2 == 'B') || (t1 == 'D' && t2 == 'F') || (t1 == 'F' && t2 == 'D'))){
        puts("00");
        return;
    }
    putchar('1');
    if(!((t1 == 'A' && t2 == 'B') || (t1 == 'B' && t2 == 'A') || (t1 == 'B' && t2 == 'C') || (t1 == 'C' && t2 == 'B') ||
         (t1 == 'D' && t2 == 'F') || (t1 == 'F' && t2 == 'D'))) puts("0");
    else puts("1");
}

signed main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
