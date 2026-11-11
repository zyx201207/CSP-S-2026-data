#include <bits/stdc++.h>
using namespace std;
long long a[5005];
int dfn[5005];
int st[5005];
int tot[5005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int co,T;
    cin>>co>>T;
    while(T--)
    {
        int n;
        long long d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        long long cnt=0;
        for(int k=1;k<=n;k++)
        {
            int lst=k;
            for(int i=1;i<=n;i++)
            {
                tot[i]=0;
                dfn[i]=0;
            }
            int t=0;
            for(int i=k;i<=n;i++)
            {
                for(lst;lst<=n;lst++)
                {
                    if(a[lst]-a[i]>d)
                    {
                        break;
                    }
                    dfn[lst]=dfn[i]+1;
                    if(t<=dfn[lst])
                    {
                        t=dfn[lst];
                    }
                    else
                    {
                        dfn[lst]=++t;
                    }
                    if(dfn[lst]!=dfn[lst-1])
                    {
                        st[dfn[lst]]=lst;
                    }
                }
            }
            dfn[n+1]=1e9;
            for(int i=k;i<=n;i++)
            {
                if(a[i]-a[i-1]>d)
                {
                    break;
                }
                if(tot[i]==0)
                {
                    tot[i]=1;
                }
                if(tot[i]==2)
                {
                    cnt++;
                }
                for(int j=st[dfn[i]+1];j<=n;j++)
                {
                    if(a[j]-a[i]>d||dfn[j]==dfn[i]||j<i)
                    {
                        break;
                    }
                    tot[j]+=tot[i];
                    if(tot[j]>2)
                    {
                        tot[j]=3;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
}
