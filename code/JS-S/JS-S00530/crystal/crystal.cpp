#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500010],s[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for (int i = 1; i <= n; i++)
        s[i] = s[i-1] + 0LL + a[i];
    for (int i = 1; i <= n; i++) {
        int l = 0, r = i;
        while (l + 1 != r) {
            int M = (l + r) / 2;
            if (1LL*(i-M+1)*a[i]-(s[i]-s[M-1]) <= m)
                r = M;
            else
                l = M;
        }
        ans = max(ans,i-r+1);
    }
    printf("%d",ans);
}
