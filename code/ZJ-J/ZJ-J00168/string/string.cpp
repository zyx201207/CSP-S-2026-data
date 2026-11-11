#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=2e5+10;
int n;
int a[maxn];
char c[maxn];
int ans;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        char ch;
        scanf(" %c",&ch);
        c[i]=ch;
    }
    int l=1,r=n;
    int num1=a[l],num2=a[r];
    char ty1=c[l],ty2=c[r];
    while(l<r)
    {
        if(num1<num2)
        {
            if(ty1!=ty2)
            {
                ans+=num1;
                num2-=num1;
                ++l;
                num1=a[l];
                ty1=c[l];
            }
            else
            {
                num2-=num1;
                ++l;
                num1=a[l];
                ty1=c[l];
            }
        }
        else if(num1>num2)
        {
            if(ty1!=ty2)
            {
                ans+=num2;
                num1-=num2;
                --r;
                num2=a[r];
                ty2=c[r];
            }
            else
            {
                num1-=num2;
                --r;
                num2=a[r];
                ty2=c[r];
            }
        }
        else
        {
            if(ty1!=ty2)
            {
                ans+=num1;
                ++l;
                --r;
                num1=a[l];
                ty1=c[l];
                num2=a[r];
                ty2=c[r];
            }
            else
            {
                ++l;
                --r;
                num1=a[l];
                ty1=c[l];
                num2=a[r];
                ty2=c[r];
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
