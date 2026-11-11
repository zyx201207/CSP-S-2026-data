#include <bits/stdc++.h>
using namespace std;
int s[1000000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int a[1000000],b[1000000];
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int k=0;k<n;k++)
    {
        for(int i=k;i<n;i++)
        {
            b[i]=a[i];
            for(int j=k;j<=i;j++)
            {
                if(b[j]==a[i])
                {
                    for(int w=j+1;w<=i;w++)
                    {
                        b[w]=0;
                    }
                }
            }
        }
        for(int i=k;i<n;i++)
        {
            if(b[i]!=0)
            {
                s[b[i]]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<s[i]<<" ";
    }
}
