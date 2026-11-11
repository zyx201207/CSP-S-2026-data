#include <bits/stdc++.h>
using namespace std;
int a[500005],shu[100005],b[500005],cnt;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    memset(shu,0,sizeof(shu));
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        memset(b,0,sizeof(b));
        cnt=1;
        for(int j=i;j<=n;j++)
        {
            bool f=true;

            for(int k=1;k<=cnt;k++)
            {
                if(b[k]==a[j])
                {
                    cnt=k+1;
                    f=false;
                }
            }
            if(f) b[cnt++]=a[j];
        }
        for(int j=1;j<cnt;j++)
        {
            shu[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<shu[i]<<" ";
}
