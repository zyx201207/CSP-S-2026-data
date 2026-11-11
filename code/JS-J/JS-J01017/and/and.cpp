#include <bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(int i = a; i <= b; i++)
#define For2(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N  = 1e6 + 5;
inline int read() {
    int x = 0; char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {x = x * 10 + c - '0';c = getchar();}
    return x;
}
int n,m,a[N];
bool ok[N];
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n = read(); m = read();
    For (i,1,n) a[i] = read();
    For (i,1,n) ok[i] = true;
    int ans = 0;
    For2 (bit,29,0) {
        int cnt = 0;
        For (i,1,n) {
            if (!ok[i]) continue;
            if (a[i] & (1 << bit)) cnt++;
        }
        if (cnt >= m) {
            ans |= (1 << bit);
            For (i,1,n) {
                if (!ok[i]) continue;
                if (!(a[i] & (1 << bit))) ok[i] = false;
            }
        }
        //cout << cnt << " ";
    }
    cout << ans << endl;
    return 0;
}
