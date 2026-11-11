#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,a[500010]={0};
    int sum=0,cnt=0,o=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>a[i-1])
           o++;
    }
    if(o==n)
    {
        cout<<n;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int t=0;
        int b[500010]={0};
        for(int j=1;j<=n-i;j++)
        {
            b[j]=a[i+j];
            for(int k=1;k<j;k++)
                if(b[k]==b[j])
                {
                    int e=b[j];
                    b[500010]={0};
                    b[1]=e;
                }
            t=j;
        }
        if(b[j]==i)
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
