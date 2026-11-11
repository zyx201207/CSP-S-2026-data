#include<bits/stdc++.h>
using namespace std;
char b[200020];
long long a[10000000]={0};
char c[10000000]={0};
int main()
{
    int n,sum=0,m=0,p=0;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            m++;
            c[m]=b[i];
        }
    }
    if(m%2==0)
    {
        for(int i=1;i<=m/2;i)
        {
            for(int j=m;j>=m/2;j--)
            {
                if(c[i]!=c[j])
                {
                    sum++;
                }
                i++;
            }
        }
    }
    else
    {
        for(int i=1;i<=m/2-1;i)
        {
            for(int j=m;j>=m/2+1;j--)
            {
                if(c[i]!=c[j])
                {
                    sum++;
                }
                i++;
            }
        }
    }
    cout<<sum;
    return 0;
}
