#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char c[200010];
long long ans = 0LL;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d %c",&a[i],&c[i]);
    int f = 1, r = n;
    while (f < r) {
        if (a[f] < a[r]) {
            if (c[f] != c[r])
                ans += 0LL + a[f];
            a[r] -= a[f], f++;
        }
        else if (a[f] == a[r]) {
            if (c[f] != c[r])
                ans += 0LL + a[f];
            r--, f++;
        }
        else {
            if (c[f] != c[r])
                ans += 0LL + a[r];
            a[f] -= a[r], r--;
        }
    }
    printf("%lld",ans);
}
