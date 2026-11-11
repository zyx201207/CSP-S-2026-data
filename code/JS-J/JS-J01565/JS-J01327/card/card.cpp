#include<bits/stdc++.h>
using namespace std;
int a[500005];
int l[250005],r[250005];
int h[500005],ans[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,s,m=0;
    cin>>n>>s;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(h[a[j]]==0)
            {
                h[a[j]]=j;
            }
            else
            {
                int f=1;
                for(int k=1;k<=m;k++)
                {
                    if(h[a[j]]<l[k])
                        break;
                    if(h[a[j]]<=r[k])
                    {
                        f=0;
                        break;
                    }
                }
                if(f==0)
                    h[a[j]]=j;
                else
                {
                    m++;
                    l[m]=h[a[j]];
                    r[m]=j;
                    h[a[j]]=0;
                }
            }
        }
        for(int j=1;j<=s;j++)
            ans[j]+=(h[a[j]]>0);
        memset(h,0,sizeof(h));
    }
    for(int i=1;i<=s;i++)
        cout<<ans[i]<<' ';
    return 0;
}
