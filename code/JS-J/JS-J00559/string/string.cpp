#include <bits/stdc++.h>
using namespace std;
long long n,a[1000001],cnt=0,m=1;
char s[1000001],c[1000001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld %c",&a[i],&c[i]);
        for(int j=m;j<=m+a[i]-1;j++)
        {
            s[j]=c[i];
        }
        m+=a[i];
    }
    m-=1;
    for(int i=1;i<=m/2+1;i++)
    {
        if(s[i]!=s[m-i+1])
        {
            s[i]=s[m-i+1];
            cnt++;
        }
    }
    cout<<cnt;

    return 0;
}
