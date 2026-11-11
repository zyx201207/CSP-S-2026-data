#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,a[20005],b[30005],c[30005],x=1,d[30005];
    memset(b,0,sizeof(b));
    memset(d,0,sizeof(d));
    memset(c,0,sizeof(c));
    memset(a,0,sizeof(a));
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int k=1;k<=n;k++)
    {
        for(long long i=k;i<=n;i++)
        {
            b[a[i]]++;
            c[x]=a[i];
            if(b[a[i]]==2)
            {
                bool flag=true;
                long long x1=x;
                for(long long j=1;j<=x1;j++)
                {
                    if(!flag)
                    {
                        b[c[j]]--;
                        c[j]=0;
                        x--;
                    }
                    if(c[j]==a[i])
                    {
                        flag=false;
                    }
                }
            }
            x++;
        }
        for(long long i=1;i<=m;i++)
        {
            d[c[i]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<d[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
