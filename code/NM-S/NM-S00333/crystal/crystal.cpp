#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int n;
ll m,a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for (int i = 0;i < n;++ i){
        scanf("%lld",&a[i]);
    }
    ll mx = 0;
    for (int i = 0;i < n;++ i){
        ll sy = m,j;
        for (j = i - 1;j >= 0 && sy >= 0 && a[j] <= a[i];-- j){
            sy -= 1ll * (a[i] - a[j]);
        }
        mx = max(mx,1ll * i - j);
    }
    printf("%lld\n",mx);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
