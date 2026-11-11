#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, d, x[2000005], v[2000005], sum1[2000005], sum2[2000005], c, t;

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
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    read(c), read(t);
    while(t--){
        read(n), read(d);
        for( int i = 1; i <= n; i++ ) read(x[i]);
        int pos = 1;
        for( int i = 1; i <= n; i++ ){
            while(pos < n && x[pos + 1] - x[i] <= d) pos++;
            v[i] = pos;
        }
        int ans = 0;
        memset(sum1, 0, sizeof(int) * (n + 1));
        memset(sum2, 0, sizeof(int) * (n + 1));
        for( int i = n - 1; i >= 1; i-- ){
            if(v[i] == i) continue;
            if(v[i] == i + 1){
                sum1[i] = sum1[i + 1] + 1;
                sum2[i] = sum2[i + 1];
                continue;
            }
            if(v[i] - 2 > i && v[v[i] - 2] == v[v[i]]){
                sum1[i] = v[i] - i;
                sum2[i] = 0;
                continue;
            }
            if(v[v[i] - 1] == v[v[i]]){
                sum2[i] = sum1[v[i]] - (v[v[i] - 2] - v[i]);
                sum1[i] = v[i] - i;
                continue;
            }
            if(v[v[i] - 1] == v[i]){
                sum2[i] = sum2[v[i]];
                sum1[i] = sum1[v[i]] + v[i] - i;
                continue;
            }
            sum1[i] = sum1[v[i]] + v[i] - i - (v[v[i] - 1] - v[v[i] - 2]);
            sum2[i] = sum2[v[i]] + v[v[i] - 1] - v[v[i] - 2];
            if(v[v[i] - 1] <= v[v[i]] - 2) continue;
            sum2[i] -= v[v[v[i] - 1]] - v[v[v[i]] - 2];
        }
        for( int i = 1; i <= n; i++ ) ans += sum2[i];
        write(ans);
    }
    return 0;
}