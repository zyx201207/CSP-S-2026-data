#include<bits/stdc++.h>
using namespace std;

using LL = long long;

const int MAXN = 5e5+10;
LL n,m,a[MAXN];
LL now_cost,l,ans;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    now_cost = a[2]-a[1];
    l = 1;ans = 0;
    for(int i=2;i<=n;i++) {
        while(l<i && now_cost > m) {
            now_cost -= a[i] - a[l];l++;
        }
        ans = max(i-l+1,ans);
        now_cost += (i-l+1)*(a[i+1]-a[i]);
    }
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
