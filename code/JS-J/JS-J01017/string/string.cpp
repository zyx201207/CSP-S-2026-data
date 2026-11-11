#include <bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(int i = a; i <= b; i++)
#define For2(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N  = 2e5 + 5;
inline int read() {
    int x = 0; char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {x = x * 10 + c - '0';c = getchar();}
    return x;
}
int n,a[N];
char c[N];
ll pre[N],suf[N];
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    n = read();
    For (i,1,n) {
        a[i] = read();
        cin >> c[i];
        pre[i] = pre[i-1] + a[i];
    }
    For2 (i,n,1) suf[i] = suf[i+1] + a[i];
    sort(suf + 1,suf + n + 1);
    ll ans = 0,pos = 0;
    For (i,1,n) {
        while (pre[i] > suf[pos]) {
            pos++;
            if (pre[i] > suf[pos] && c[i] != c[n-pos+1]) ans += suf[pos] - suf[pos-1];
            if (suf[pos] >= pre[i] && c[i] != c[n-pos+1]) ans += pre[i] - suf[pos-1];
        }
        if (pre[i] < suf[pos] && c[i+1] != c[n-pos+1]) ans += min(suf[pos],pre[i+1]) - pre[i];
    }
    cout << ans / 2 << endl;
    return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
