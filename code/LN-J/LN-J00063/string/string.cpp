#include <bits/stdc++.h>
using namespace std;
long long n;
int k=0;
char s[500030];
char y;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        long long x;
        scanf("%lld",&x);
        cin>>y;
        for(int j=0;j<=x;j++)
        {
            s[j+k]=y;
        }
        k+=x;
    }
    long long ans=0;
    long long i=0,j=k;
    while(i<=j)
    {
        if(s[i]!=s[j])
        {
            ans++;
        }
        i++;
        j--;
    }
    printf("%lld",ans);
    return 0;
  }
