#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],f=1,b[300010],c[300010],d[300010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<a[i-1])
        {
            f=0;
        }
    }
    if(f)
    {
        for(int i=1;i<=n;i++)
        {
            memset(c,0,sizeof(c));
            for(int j=i;j<=n;j++)
            {
                int cnt=1;
                while(a[j+1]==a[j])
                {
                    j++;
                    cnt++;
                }
                if(cnt%2==1&&c[a[j]]==0)
                {
                    b[a[j]]++;
                    c[a[j]]=1;
                }
            }
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            memset(c,0,sizeof(c));
            int z=1;
            for(int j=i;j<=n;j++)
            {
                int g=1;
                for(int k=j+1;k<=n;k++)
                {
                    if(a[j]==a[k])
                    {
                        j=k;
                        g=0;
                        break;
                    }
                }
                if(g)
                {
                    d[z++]=a[j];
                }
            }
            for(int j=1;j<z;j++)
            {
                if(c[d[j]]==0)
                {
                    c[d[j]]=1;
                    b[d[j]]++;
                }
            }
            cout<<endl;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}
