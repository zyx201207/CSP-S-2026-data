#include<bits/stdc++.h>
using namespace std;
int m;
long long ans = 0;
int a[20005];
char ac[20005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&m);
    for(int i = 1;i <= m;i++)
    {
        scanf("%d",&a[i]);
        getchar();
        scanf("%c",&ac[i]);
    }
    int l = 1,r = m;
    while(l < r)
    {
        if(ac[l] == ac[r])
        {
            if(a[l] == a[r])
            {
                r--;
                l++;
            }
            else if(a[l] > a[r])
            {
                a[l] -= a[r];
                r--;
            }
            else if(a[l] < a[r])
            {
                a[r] -= a[l];
                l++;
            }
        }
        else
        {
            if(a[l] == a[r])
            {
                r--;
                l++;
                ans += a[l];
            }
            else if(a[l] > a[r])
            {
                a[l] -= a[r];
                ans += a[r];
                r--;
            }
            else if(a[l] < a[r])
            {
                a[r] -= a[l];
                ans += a[l];
                l++;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
