#include<bits/stdc++.h>
using namespace std;
int a[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=1;j<=i-1;j++)
        {
            if(a[j]==a[i]&&a[i]!=0)
            {
                for(int k=j;k<=i;k++)
                {
                    a[k]=0;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=0)
        {
            cout<<a[i]<<' ';
        }
    }















    return 0;
}

