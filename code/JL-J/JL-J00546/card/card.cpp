#include <bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[500001],f[300001],ans[300001];
bool ff=true;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<a[i-1])
            ff=false;
    }
    if(ff==true)
    {
        for(int i=1;i<=n;i++)
            ans[a[i]]++;
        for(int i=1;i<=m;i++)
           ans[i]+=ans[i-1],cout<<ans[i]<<" ";
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            int k=0;
            memset(f,0,sizeof(f));
            for(int l=i;l<=n;l++)
            {
                if(f[a[l]]==0)
                {
                    k++;
                    f[a[l]]=k;
                    b[k]=a[l];
                }
                else
                {
                    for(int j=f[a[l]]+1;j<=k;j++)
                    {
                        f[b[j]]=0;
                    }
                    k=f[a[l]];
                }
            }
            for(int l=1;l<=m;l++)
            {
                if(f[l])
                ans[l]++;
            }
        }
        for(int i=1;i<=m;i++)
           cout<<ans[i]<<" ";
    }
    return 0;
}
