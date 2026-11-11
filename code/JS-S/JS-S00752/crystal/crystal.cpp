#include<bits/stdc++.h>
using namespace std;
long long ba[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long m,n;
    cin>>n>>m;
    long long z=0;
    int yyw=0;
    for(long long i=1;i<=n;i++)
    {
        cin>>ba[i];
        if(ba[i]!=i)
            yyw=1;
    }
    if(yyw==0)
    {
        if(m>=n*(n-1)/2)
            z=n-1;
        else
        {
            for(long long i=1;i<=n;i++)
            {
                if(i*(i-1)/2>m)
                    {
                        z=i;
                        break;
                    }
            }
        }
    }
    else
    {
        for(long long i=2;i<=n;i++)
        {
            long long j=i;
            while(j>1)
            {
                if(ba[j-1]>ba[j])
                {
                    long long o=ba[j];
                    ba[j]=ba[j-1];
                    ba[j-1]=o;
                    j--;
                }
                else
                    break;

            }
        }
        for(long long i=2;i<=n;i++)
        {
            long long y=1;long long  x=m;
            for(long long j=i-1;j>0;j--)
            {
                if(ba[i]-ba[j]<=x)
                {
                    x=x-ba[i]+ba[j];
                    y++;
                }
                else
                    break;
            }
            z=max(z,y);
        }
    }

    cout<<z;
    return 0;
}
