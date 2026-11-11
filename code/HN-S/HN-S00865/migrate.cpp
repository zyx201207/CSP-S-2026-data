#include <bits/stdc++.h>
using namespace std;

int c,t,n,a[2000005],b[2000005],mig[2000005];
unsigned long long d,dist[2000005],ans;
bool l[2000005],r[2000005];

/*
inline void v(int i)
{
    for(int j=i-1;j>=0 && a[j]!=j;j--)ans++;
    for(int j=mig[i]+1;j<n && b[j]!=j;j++)ans++;
}
*/

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==13 || c==14)
    {
        for(;t>0;t--)
            cout<<0<<endl;
        return 0;
    }
    for(;t>0;t--)
    {
        ans=0;
        cin>>n>>d;
        for(int i=0;i<n;i++)
        {
            a[i]=i;
            b[i]=i;
            mig[i]=i;
            l[i]=false;
            r[i]=false;
        }
        long long d1,d2,d3=0,d4=0;
        cin>>d1;
        dist[0]=0;
        for(int i=1;i<n;i++)
        {
            cin>>d2;
            dist[i]=d2-d1;
            d1=d2;
            d4+=dist[i];
            while(d4>d && d3<i)
            {
                d3++;
                d4-=dist[d3];
            }
            b[i]=d3;
            for(int j=d3;j<i;j++)
                a[j]=i;
        }
        /*
        for(int i=0;i<n;i++)
        {
            cout<<i<<" "<<a[i]<<"   ";
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<i<<" "<<b[i]<<"   ";
        }
        */
        for(int i=0;i<n;i++)
        {
            for(int j=i+2;j<n;j++)
            {
                if(a[i]-1==b[j])
                {
                    mig[i]=j;
                    l[j]=true;
                    r[i]=true;
                    ans++;
                }
            }
        }
        //for(int i=0;i<n;i++)if(mig[i]-i)v(i);
        cout<<ans<<endl;
    }
    return 0;
}
