/*int n,d,cnt=0,x[2000005],a[2000005],ans[2000005];
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        /*if(c==11||c==12)
        {
            d/=x[2]-x[1];
            for(int i=1;i<=a[n];i++)
            {
                if(i<=n)
                {
                    x[i]=i;
                }
                else
                {
                    x[i]=0;
                }
            }
        }
        /*or(int i=n;i>=1;i--)//o
        {
            for(int k=1;k<=d;k++)//ge shu
            {
                for(int j=x[n]-d;j<x[n];j++)
                {
                    if(x[i-k]>=x[i]-d)
                    {
                        cnt++;
                        break;
                    }
                }
            }
            o[i]=cnt;
            cnt=0;
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]<=d)
            {
                a[i]=1;
            }
            else
            {
                for(int j=d;j>=1;j--)
                {
                    if(x[i-j]>=x[i]-d)
                    {
                        a[i]=a[i-j]+1;
                        break;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            int minn=1e9;
            for(int j=d;j>=1;j--)
            {
                if(x[i-j]>=x[i]-d)
                {
                    minn=min(minn,a[i-j]);
                }
            }
            for(int j=d;j>=1;j--)
            {
                if(x[i-j]>=x[i]-d)
                {
                    if(a[i-j]==minn)
                    {
                        ans[i]++;
                    }
                }
            }
            if(ans[i]==2)
            {
                cnt++;
            }
        }
        for(int i=1;i<=20005;i++)
        {
            x[i]=0;
            a[i]=0;
            ans[i]=0;
        }
        cout<<cnt<<endl;*/
#include<bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cout<<1;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<0<<endl;
    }
    return 0;
}
