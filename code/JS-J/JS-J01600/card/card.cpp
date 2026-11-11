#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int h[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int f=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]!=a[i])
        {
            f=1;
            break;
        }
    }
    if(f==0)
    {
        for(int i=1;i<=n;i++)
        {
            h[a[i]]=i;
        }
        for(int i=1;i<=m;i++)
        {
            cout<<h[i]<<" ";
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            int h1[500005],x[500005];
            memset(x,0,sizeof(x));
            memset(h1,0,sizeof(h1));
            int cnt=1;
            for(int j=i;j<=n;j++)
            {
                if(h1[a[j]]!=0)
                {
                    cnt=h1[a[j]];
                    for(int k=h1[a[j]]+1;k<=j;k++)
                    {
                        h1[x[k]]=0;
                        x[k]=0;
                    }
                }
                x[cnt]=a[j];
                h1[a[j]]=cnt;
                cnt++;
            }
            for(int j=1;j<=n;j++)
            {
                if(h1[j]!=0)
                {
                    h[j]++;
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            cout<<h[i]<<" ";
        }
    }
    return 0;
}
