#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+6;
long long n,m,q,w,e,a[N],s[N],d[N],ans,t,c;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12)
    {
        while(t--)
        {
            cin>>n>>m;
            for(int i=1;i<=n;i++)
            {
                cin>>a[i];
            }
            if(n==1)
            {
                cout<<"0\n";
                continue;
            }
            m/=(a[2]-a[1]);
            if(m==1||m==0)
            {
                cout<<"0\n";
                continue;
            }
            cout<<max(n-m-1,(long long)0)<<"\n";
        }
        return 0;
    }
    while(t--)
    {
        q=w=e=ans=0;
        cin>>n>>m;
        for(long long i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(long long i=1;i<=n;i++)
        {
            d[i]=1;
            s[i]=0;
            q=i;
            for(long long j=i-1;j>=1;j--)
            {
                if(a[j+1]-a[j]>m) break; 
                while(a[q]-a[j]>m)
                {
                    q--;
                }
                if(j==i-1)
                {
                    s[j]=1;
                    d[j]=1;
                }
                else if(j==i-2)
                {
                    if(a[i]-a[j]<=m)
                    {
                        s[j]=1;
                        d[j]=1;
                    }
                    else
                    {
                        s[j]=2;
                        d[j]=1;
                    }
                }
                else
                {
                    s[j]=s[q]+1;
                    if(q==j+1)
                    {
                        d[j]=d[q];
                    }
                    else
                    {
                        w=0;
                        w+=d[q];
                        if(s[q-1]+1==s[j])
                        {
                            w+=d[q-1];
                        }
                        if(q>j+2&&s[q-2]+1==s[j])
                        {
                            w+=d[q-2];
                        }
                        d[j]=w;
                    }
                }
                if(d[j]==2) ans++;
                if(d[j]>2) d[j]=3;
            }
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}//long long
            