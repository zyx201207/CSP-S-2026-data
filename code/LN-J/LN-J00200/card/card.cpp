#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[300005],xc=1,xk,m[300005],xy=1;
bool f,b;
int main()
{
    feropen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        for(int j=1;j<=i;j++)
        {
            if(a[i]==m[i])
            {
                b=1;
            }
        }
        if(b==0)
        {
            m[xy]=a[i];
            xy++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            for(int k=1;k<=xc;k++)
            {
                if(a[j]!=a[k])
                {
                    f=1;
                    xk=k;
                    break;
                }
            }
            if(f==1)
            {
                for(int k=xk+1;k<=xc;k++)
                {
                    c[k]=0;
                }
                xc=xk+1;
            }
            else
            {
                c[xc]=a[j];
                xc++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        int y==0
        for(int j=1;j<xc;j++)
        {
            if(c[j]==m[i])
            {
                y++;
            }
        }
        cout <<y;
    }
    return 0;
}
