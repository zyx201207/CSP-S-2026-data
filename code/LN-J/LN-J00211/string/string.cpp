#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,ans,in;
char t;
string o;

signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld %c",&in,&t);
        for(int j=1;j<=in;j++)o+=t;
    }
    for(int i=0,j=n;(j-i)>=1;i++,j--)
    {
        if(o[i]!=o[j])ans++;
    }
    printf("%lld\n",ans);
}