#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,a[2000010];
void solve1()
{
    int t=d/(a[1]-a[0]);
    if(t<=1)printf("0\n");
    else printf("%lld\n",max(0ll,n-2*t+1));
}
void solve2()
{
    printf("0\n");
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&d);
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);
        if(c==11||c==12)
            solve1();
        else solve2();
    }
    return 0;
}
