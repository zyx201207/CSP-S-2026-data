#include <bits/stdc++.h>
using namespace std;
long long m[20001];
char a[200001];
char t[2000000001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long x=1,l=0,y=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%s",&m[i],&a[i]);
        l+=m[i];
        for(int j=1;j<=m[i];j++)
        {
            t[x]=a[i];
            x++;
        }
    }
    for(int i=1;i<=l/2;i++)
    {
        if(t[i]!=t[l+1-i])
        {
            y++;
        }
    }
    printf("%lld",y);
    return 0;
}
