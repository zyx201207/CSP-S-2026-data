#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,a[6000],s[6000],c[6000];
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++)//suoyou
    {
        long long lo=0;
        for(long long j=i;j<=n;j++)//meiju
        {
            long long bol=0;
            if(lo==0)
            {
                lo++;
                c[1]=a[j];
            }
            else
            {
                lo++;
                c[lo]=a[j];
            }

            for(long long l=1;l<=lo;l++)
            {

                if(c[l]==a[j])
                {
                    bol=l+1;
                    break;
                }
            }
           for(long long l=bol;l<=lo;l++)
           {

               c[l]=0;
           }

        }
        for(long long j=1;j<=lo;j++)
        {
            for(long long l=1;l<=m;l++)
            {
                if(c[j]==l)
                {
                    s[l]++;
                }
            }
        }
        lo=0;
    }
    for(long long i=1;i<=m;i++)
    {
        cout<<s[i]<<" ";
    }
    return 0;
}


