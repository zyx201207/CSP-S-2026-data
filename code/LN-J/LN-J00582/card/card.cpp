#include <bits/stdc++.h>
using namespace std;
int a[200001];
int b[200001];
int d[200001];
int c[200001];
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
            b[a[j]]++;
            if(b[a[j]]==2)
            {
                for(int l=d[a[j]];l<=j;l++)
                {
                    b[a[l]]=0;
                }
            }
            else d[a[j]]=j;
        }
        for(int k=1;k<=n;k++)
        {
            if(b[a[k]]>0&&b[a[k])
            {
                c[k]++;
            }
        }
        for(int i=1;i<=20000;i++)
        {
            b[i]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<c[i]<<" ";
    }
    return 0;
}
