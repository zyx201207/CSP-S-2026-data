#include <bits/stdc++.h>
#define int long long
using namespace std;
char ch[200005];
int cnt[200005];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0ll;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld %c",&cnt[i],&ch[i]);
    }
    for(int i=1,j=n;i<j;)
    {
        int k=min(cnt[i],cnt[j]);
        if(ch[i]!=ch[j])ans+=k;
        if(cnt[i]==cnt[j])i++,j--;
        else if(cnt[i]<cnt[j])i++,cnt[j]-=k;
        else if(cnt[i]>cnt[j])j--,cnt[i]-=k;
    }
    printf("%lld\n",ans);
    return 0;
}
