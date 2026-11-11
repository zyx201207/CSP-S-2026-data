#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500001],b[500001],d[500001];
    memset(b,0,sizeof(b));
    memset(d,0,sizeof(d));
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=i;j<=n;j++)
        {
            if(d[a[j]]!=0)
            for(int k=d[a[j]];k<j;k++) d[a[k]]=0;
            d[a[j]]=j;
           // else
        }
        //cout<<d[1]<<d[2]<<d[3]<<endl;
        for(int j=1;j<=m;j++)
        {
            if(d[j]!=0)
                    b[j]++;
           // else
           d[j]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        printf("%d ",b[i]);//scanf("%d",&a[i]);
    }
    //
}
