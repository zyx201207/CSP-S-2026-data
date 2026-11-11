#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int maxn = 2e5+10;

int num[maxn];
char s[maxn];

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    #endif // ONLINE_JUDGE

    int n;
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld %c",&num[i],&s[i]);
    }

    int ans=0;
    int i=1,j=n,tmp;
    while(i<j)
    {
        tmp=min(num[i],num[j]);
        if(s[i]!=s[j])
        {
            ans+=tmp;
        }
        num[i]-=tmp; num[j]-=tmp;
        if(!num[i]) ++i;
        if(!num[j]) --j;
    }
    printf("%lld\n",ans);

    return 0;
}
















