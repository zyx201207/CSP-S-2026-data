#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 10;
int n,m;
ll ans;
ll a[maxn];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a + 1,a + 1 + n,greater<int>());
    ans = a[1];
    for(int i=2;i<=m;i++)
    {
        ans &= a[i];
    }
    printf("%lld\n",ans);
    return 0;
}