#include<bits/stdc++.h>
using namespace std;
int ca,t,a[1000005],b,c;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d %d",&ca,&t);
    for(int T=0;T<t;T++)
    {
        int n,d;
        scanf("%d %d",&n,&d);
        for(int i=1;i<=n;i++)
            scanf("%d ",&a[i]);
        b=a[1];
        c=a[2];
        c-=b;
        n--;
        int ans=0;
        for(int i=0;i*c<n;i++)
        {
            int x=i*c;
            b=n%x;
            if(n/i>1)
                ans+=(n/x-2)*(x-1)+(2*b);
            else
                ans+=2*b;
        }
    }
    return 0;
}
