#include <bits/stdc++.h>
using namespace std;
int x[200005],s[200005],a[200005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,num=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int i=num;i<=n;i++)
        {
            a[i]=s[i];
            for(int j=num;j<=i-1;j++)
            {
                if(a[j]==a[i])
                {
                    for(int k=j;k<=i-1;k++)
                    {
                        a[k]=0;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            x[a[i]]++;
        }
        for(int i=1;i<=n;i++) a[i]=0;
        num++;
    }
    for(int i=1;i<=m;i++) cout<<(x[i]>=n?n:x[i])<<" ";
    return 0;
}
