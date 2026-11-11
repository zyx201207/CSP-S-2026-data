#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005]={0},max1=0,min1=10000000000;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]>max1)
            {
                max1=a[i];
            }
        }
        cout<<max1;
        return 0;
    }
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[i]&a[j]>max1)
                {
                    max1=a[i]&a[j];
                }
            }
        }
        cout<<max1;
        return 0;
    }
}
