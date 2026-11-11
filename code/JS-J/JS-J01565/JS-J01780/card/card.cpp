#include <bits/stdc++.h>
using namespace std;
int a[500005],k[300005],d[300005];
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
        int cnt=0;
        memset(d,0,sizeof(d));
        for(int j=i;j<=n;j++)
        {
            int f=1,w=cnt;
            for(int q=1;q<=cnt;q++)
            {
                if(d[q]==a[j])
                {
                    f=0;
                    w=q;
                }
            }
            if(f==0)
            {
                for(int q=w;q<=cnt;q++)
                {
                    d[q]=0;
                }
            }
            cnt = w+1;
            d[cnt]=a[j];
        }
        for(int j=1;j<=cnt;j++)
        {
            k[d[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<k[i]<<" ";
    }
    return 0;
}
