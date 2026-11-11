#include <bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld %c",&a[i],&c[i]);
    }
    int i=1,j=n;
    long long cnt=0;
    while(i<j)
    {
        if(c[i]!=c[j])
        {
            if(a[i]>a[j])
            {
                a[i]-=a[j];
                cnt+=a[j];
                j--;
            }
            else if(a[j]>a[i])
            {
                a[j]-=a[i];
                cnt+=a[i];
                i++;
            }
            else
            {
                cnt+=a[i];
                i++;
                j--;
            }
        }
        else
        {
            if(a[i]>a[j])
            {
                a[i]-=a[j];
                j--;
            }
            else if(a[i]<a[j])
            {
                a[j]-=a[i];
                i++;
            }
            else
            {
                i++;j--;
            }
        }
    }
    printf("%lld",cnt);
    return 0;
}
