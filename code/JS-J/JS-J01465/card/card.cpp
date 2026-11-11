#include<bits/stdc++.h>
using namespace std;
int a[500005];
int d[500005];
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
        int pos=i;
        int b[500005]={0};
        int c[500005]={0};
        for(int j=i;j<=n;j++)
        {
            if(b[a[j]]==0)
            {
                b[a[j]]=j;
            }
            else
            {

                for(int t=b[a[j]]+1;t<pos;t++)
                {
                    b[c[t]]=0;
                }
                pos=b[a[j]];
            }
            c[pos]=a[j];
            pos++;
        }
        int cnt=0;
        for(int j=i;j<pos;j++)
        {
            d[c[j]]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<d[i]<<" ";
    return 0;
}
