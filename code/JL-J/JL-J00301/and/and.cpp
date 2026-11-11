#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
int n,m;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        for(long long i=0;i<=n;i++)
        {
            if(a[i]>max)
            {
                max=a[i];
            }
        }
        cout<<max;
        return 0;
    }
    else if(m==n)
    {
        max=a[0];
        for(int i=1;i<n;i++)
        {
            max=max&a[i];
        }
        cout<<max;
        return 0;
    }
    else if(m==2)
    {
        for(int i=0;i<n;i++)
        {
             for(int j=i+1;j<n;j++)
             {
                 int t;
                 t=a[i]&a[j];
                 if(t>max)max=t;
             }
        }
        cout<<max;
        return 0;
    }
    return 0;
}
