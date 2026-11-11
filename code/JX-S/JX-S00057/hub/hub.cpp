#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,js=1;
    cin>>c>>t;
    int n,m,a[100005],ans=0,re=0;
    for(int k=1;k<=t;k++)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(a[j]<a[i])
                {
                    re=a[j];
                    a[j]=a[i];
                    a[i]=re;
                }
            }
        }
        for(int i=n;i>1;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(a[j]>=0 && a[i]>=0)
                {
                    if(a[j]-a[i]>m)
                    ans++;
                }
                else
                {
                    if(a[j]+a[i]>m)
                    ans++;
                }
            }
        }
        cout<<ans<<" ";
    }
    return 0;
}
