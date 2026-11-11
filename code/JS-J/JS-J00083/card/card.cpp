#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int num = 0,sign = 1;char ch = getchar();
    while(ch < '0' || ch > '9') sign = (ch == '-' ? -1 : 1),ch = getchar();
    while('0' <= ch && ch <= '9') num = (num << 3) + (num << 1) + ch -'0',ch = getchar();
    return (sign > 0 ? num : -num);
}
const int maxn = 5e5 + 8,maxm = 3e5 + 8;
int n,m,a[maxn],b[maxm],c[maxn],ans[maxm];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n = read(),m = read();
    for(int i = 1;i <= n;i++) a[i] = read();
    for(int i = n;i >= 1;i--) c[i] = b[a[i]],b[a[i]] = i;
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            ans[a[j]]++;
            if(c[j] > 0) ans[a[j]]--,j = c[j] - 1;
        }
    }
    for(int i = 1;i <= m;i++) cout << ans[i] << ' ';
    return 0;
}
