#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
    ll num = 0,sign = 1;char ch = getchar();
    while(ch < '0' || ch > '9') sign = (ch == '-' ? -1 : 1),ch = getchar();
    while('0' <= ch && ch <= '9') num = (num << 3) + (num << 1) + ch -'0',ch = getchar();
    return (sign > 0 ? num : -num);
}
const int maxn = 2e5 + 8;
ll n,m,a[maxn],b[maxn][30],c[30],vis[maxn],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n = read(),m = read();
    for(int i = 1;i <= n;i++) a[i] = read();
    for(int i = 1;i <= n;i++){
        int j = 0;
        while(a[i]){
            if(a[i] & 1) b[i][j] = 1,c[j]++;
            a[i] >>= 1,j++;
        }
    }
    for(int i = 29;i >= 0;i--){
        if(c[i] < m) continue;
        ans += 1 << i;
        for(int j = 1;j <= n;j++){
            if(vis[j]) continue;
            if(b[j][i] != 1){
                vis[j] = 1;
                for(int k = 0;k < 30;k++) c[k] -= b[j][k];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
