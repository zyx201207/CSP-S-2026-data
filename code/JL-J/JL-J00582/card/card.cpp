#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[500010];
int c[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            b[i]=a[i];
        }
        for(int j=i;j<=n;j++)
        {
            for(int x=i;x<=j;x++)
            {
                if(b[x]==b[j])
                {
                    for(int y=x;y<=j-1;y++)
                    {
                        b[y]=INT_MAX;
                    }
                }
            }
        }
        for(int j=i;j<=n;j++)
        {
            if(b[j]!=INT_MAX)
            {
                c[b[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<c[i]<<' ';
    }
    return 0;
}
