#include<bits/stdc++.h>
using namespace std;
int h[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","r",stdout);
    int n,m;
    int a[500005];
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        int s[500005];
        bool c[500005];
        for(int j=0;j<n;j++)
        {
            c[j]=0;
        }
        for(int j=i;j<n;j++)
        {
            s[j]=a[j];
        }
        for(int j=i;j<n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                if(s[j]==s[k])
                {
                    for(int z=j;z<=k;z++)
                    {
                        c[j]=1;
                    }
                }
            }
        }
        for(int j=i;j<n;j++)
        {
            if(c[j]==0)
            {
                h[s[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<h[i]<<' ';
    }
    return 0;
}
