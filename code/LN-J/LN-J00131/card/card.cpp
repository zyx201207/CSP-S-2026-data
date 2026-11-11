#include <bits/stdc++.h>
using namespace std;
int a,b;
int q[500005],sum[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;i++)
    {
        cin>>q[i];
    }
    for(int i=1;i<=a;i++)
    {
        for(int j=a-i+1;j<=a;j++)
        {
            for(int l=j+1;l<=a;l++)
            {
                if(q[j]==q[l])
                {
                    j=l;
                }
            }
            sum[q[j]]++;
        }
    }
    for(int i=1;i<=b;i++)
    {
        cout<<sum[i]<<' ';
    }
    return 0;
}
