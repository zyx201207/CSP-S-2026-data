#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],z[N],t[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.in","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(z,0,sizeof z);
        for(int j=i;j<=n;j++)
        {
            z[j]=a[j];
        }
        for(int j=i;j<=n;j++)
        {
            for(int k=i;k<j;k++)
            {
                if(z[j]==z[k])
                {
                    for(int l=k;l<j;l++)
                    {
                        z[l]=0;
                    }
                }
            }
        }
        for(int j=i;j<=n;j++)
        {
            if(z[i]!=0) t[z[i]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<t[i]<<" ";
    }
    return 0;
}
