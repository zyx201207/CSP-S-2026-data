#include <bits/stdc++.h>
using namespace std;
long long int n,m;
long long int a[500000];

long long int x=-1000000000000;
long long int num=0;

bool B=1;

void check(int y)
{
    long long int sum=1;
    long long int p=y;
    while (p<=n)
    {
        if(a[++p]==a[y]) sum++;
    }
    long long int q=0;
    p=y;
    long long int r=0;
    while(p>0)
    {
        if(r>m)
        {
            break;

        }else
        {
            long long int u=a[y]-a[--p];
            r+=u;
            if(r>m)
            {
                r-=u;
                break;
            }
            sum++;
        }
    }
    num=max(num,sum);

    return ;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);






    //cout<<lower_bound(a,a+5,1)-a-1;

    scanf("%lld%lld",&n,&m);

    for(int i=0; i<n; i++)
    {
        scanf("%lld",&a[i]);
        x=max(x,a[i]);


    }
    sort(a,a+n);
    long long int l=a[1]-a[0];
    for (int i=0; i<n-1; i++)
    {
        if(a[i+1]-a[i]!=l) B=0;

    }
    if(B)
    {
        long long int e=m/l;
        if(e==0)
        {
            printf("1\n");

        }else{
            printf("%lld\n",min(e+1,n));
        }

        return 0;
    }
    for (int i=n-1;i>=0;i--)
    {

        check(i);
    }
    printf("%lld\n",num);





    return 0;
}
