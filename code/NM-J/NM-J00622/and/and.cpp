#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[300010];

int main()
{
    //444444444444444444444444444444444444444444
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }

    sort(a,a+n+1);

    if(m==1)
    {
        cout<<a[n];
    }
    else if(m==2)
    {
        long long ma=-1;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                int t=a[i] & a[j];
                if(t>ma && i!=j)
                {
                    ma=t;
                }
            }
        }
        cout<<ma;
    }
    else if(m==n)
    {
        int lt=a[1],t;
        for(int i=2; i<=n; i++)
        {
            t=lt & a[i];
            lt=t;
        }
        cout<<lt;
    }
    else
    {
        cout<<0;
    }


    return 0;
}
