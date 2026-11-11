#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500002],b[300002],c[300002];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[a[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        int l=i,r=n;
        int k=i-1;
        for(int j=i;j<=n;j++)
        {
            b[j]=a[j];
        }
        for(int j=i;j<=n;j++)
        {
            while(c[a[r]]<2) r--;
            if(a[j]==a[r])
            {
                k=j-1;
                break;
            }
        }
        for(int j=i;j<=k;j++)
        {
            b[j]=0;
        }
        for(int j=i;j<=n;j++)
        {
            c[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<c[i]-1<<" ";
    }
    return 0;
}
