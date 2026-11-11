#include<bits/stdc++.h>
using namespace std;
int n;
char ci;
long long sum,sum1,sum2;
char c[2*1000000000+14748000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    int a;
    for(int i=1;i<=n;i++)
    {
        scanf("%d %c",&a,&ci);
        for(int j=1;j<=a;j++)
            c[sum+j]=ci;

        sum+=a;

    }
    for (long long i=1;i<=sum-i;i++)
    {
        if(c[i]!=c[sum-i+1])sum1++;

    }

    printf("%lld",sum1);

    return 0;
}

