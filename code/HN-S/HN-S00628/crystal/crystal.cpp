#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], ans;

template<typename type>
inline void read(type &x){
    x=0;bool flag(0);char ch=getchar();
    while(!isdigit(ch)) flag=ch=='-',ch=getchar();
    while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    flag?x=-x:0;
}
template<typename type>
inline void write(type x, bool mode=1){
    x<0?x=-x,putchar('-'):0;static short Stack[50],Top(0);
    do Stack[++Top]=x%10,x/=10; while(x);
    while(Top) putchar(Stack[Top--]|48);
    mode?putchar('\n'):putchar(' ');
}

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    read(n), read(m);
    for( int i = 1; i <= n; i++ ) read(a[i]);
    sort(a + 1, a + n + 1);
    int pos = n;
    for( int i = n; i >= 1; i-- ){
        while(pos && a[i] - a[pos] <= m){
            m -= a[i] - a[pos];
            pos--;
        }
        ans = max(ans, i - pos);
        m += (a[i] - a[i - 1]) * (i - pos - 1);
    }
    write(ans);
    return 0;
}