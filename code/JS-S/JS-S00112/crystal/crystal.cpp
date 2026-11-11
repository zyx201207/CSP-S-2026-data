#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
    ll num = 0,sign = 1;char ch = getchar();
    while(ch < '0' || ch > '9') sign = (ch == '-' ? -1 : 1),ch = getchar();
    while('0' <= ch && ch <= '9') num = (num << 3) + (num << 1) + ch - '0',ch = getchar();
    return (sign > 0 ? num : -num);
}
const int maxn = 5e5 + 8;
ll n,m,a[maxn],x;int ans;bool A = 1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n = read(),m = read();
    for(int i = 1;i <= n;i++){
        a[i] = read();
        if(i > 2) A = (A && x == a[i] - a[i - 1]);
        if(i > 1) x = a[i] - a[i - 1];
    }
    if(A){
        m /= x;
        for(int i = 1;i <= n;i++)
            if((i + 1) * i / 2 <= m) ans = i;
        cout << ans + 1 << '\n';
        return 0;
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++){
        ll x = 0;
        for(int j = i - 1;j >= 0;j--){
            if(x + a[i] - a[j] <= m && j != 0) x += a[i] - a[j];
            else{
                ans = max(ans,i - j);
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
