#include<bits/stdc++.h>
using namespace std;
#define int long long

inline int read(){
    char c = getchar();
    int f = 0, g = 1;
    while(c < '0' || c > '9'){
        if(c == '-') g = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        f = (f<<3)+(f<<1)+c-'0';
        c = getchar();
    }
    return f*g;
}

const int N = 5e5+10;
int n, m, nowc, nowl, a[N], ans;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    n = read();
    m = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    sort(a+1,a+n+1);
    nowl = 1;
    for(int i = 1; i <= n; i++){
        nowc += (i-nowl)*(a[i]-a[i-1]);
        while(nowc > m){
            nowc -= (a[i]-a[nowl]);
            ++nowl;
        }
        ans = max(ans,i-nowl+1);
    }
    cout << ans << "\n";
}