#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
    ll num = 0,sign = 1;char ch = getchar();
    while(ch < '0' || ch > '9') sign = (ch == '-' ? -1 : 1),ch = getchar();
    while('0' <= ch && ch <= '9') num = (num << 3) + (num << 1) + ch - '0',ch = getchar();
    return (sign > 0 ? num : -num);
}
const int maxn = 2e6 + 8,maxk = 1e6 + 8;
int n,k,a[maxk];ll ans;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c = read(),t = read();
    while(t--){
        n = read(),k = read();
        cout << (n - k) / (k + 1) + ((n / k) % (k + 1) ? 1 : 0) << '\n';
    }
    return 0;
}
