#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000],mx=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }


    for(long long i=1;i<=n-1;i++)
    {
        for(long long j=i+1;j<=n;j++)
        {

            long long mad=0,md[10000];
            long long b1[10000],b2[10000],t1=1,ai=a[i],aj=a[j],t2=1;

            for(long long z=1;z<=9999;z++)
            {
                md[z]=0;b1[z]=0;b2[z]=0;
            }

            while(ai!=0)
            {
                b1[t1]=ai%2;
                t1++;
                ai=ai/2;
            }

            while(aj!=0)
            {
                b2[t2]=aj%2;
                t2++;
                aj=aj/2;
            }

            for(long long l=1;l<=max(t1,t2);l++)
            {
                if(b1[l]==1&&b2[l]==1)
                {
                    md[l]=1;
                }
                else
                {
                    md[l]=0;
                }
            }

            for(long long l=1;l<=max(t1,t2);l++)
            {
                long long f=1;
                for(long long r=2;r<=l;r++)
                {
                    f*=2;
                }
                mad+=md[l]*f;

            }
            mx=max(mx,mad);

        }
    }
    cout<<mx;
    return 0;
}
