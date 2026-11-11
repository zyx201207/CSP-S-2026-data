#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m;
ll a[500005];
ll pre[500005];
bool check(int l,int r)
{
    return (r - l + 1) * a[r] - (pre[r] - pre[l - 1]) <= m;
}
int ans = 0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for (int i = 1;i <= n; i++)
        scanf("%lld",a + i);
    sort(a + 1,a + 1 + n);
    int l = 1;
    for (int i = 1;i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
        while(l <= i && !check(l,i))
            l++;
        ans = max(ans,i - l + 1);
    }
    printf("%d\n",ans);
    return 0;
}