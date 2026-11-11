#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin >>a[i];
    }

    int b[m+1];
    memset(b,0,sizeof(b));
    if(n<=4000)
    {
        int t=n;
        while(t--)
        {
            int c[n+1];
            memset(c,0,sizeof(c));
            for(int i=n-t;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(c[j]==0)
                    {
                        c[j]=a[i];
                        break;
                    }
                    if(a[i]==c[j])
                    {
                        for(int k=j+1;k<=n;k++)
                        {
                            if(c[k]==0)
                            {
                                break;
                            }
                            c[k]=0;
                        }
                        break;
                    }
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(c[i]==0)
                {
                    break;
                }
                b[c[i]]++;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cout <<b[i]<<" ";
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            b[a[i]]++;
        }
        for(int i=1;i<=m;i++)
        {
            cout <<b[i]<<" ";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
