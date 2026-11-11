#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans;
long long a[200005];
char b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        if(i==1)
        {
            cin>>a[i];
            cin>>b[i];
            continue;
        }
        long long x;
        cin>>x;
        a[i]=a[i-1]+x;
        cin>>b[i];
    }
    a[0]=0;
    long long i;
    for(i=1;i<=(n+1)/2;i++)
    {
        long long x=n-i+1;
        if(b[i]==b[x]&&i!=x)
        {
            long long y=(a[i]-a[i-1])-(a[x]-a[x-1]);
            if(y>0)
            {
                a[x-1]-=y;
                ans+=y;
            }
            else if(y==0)
            {
                continue;
            }
            else if(y<0)
            {
                b[x+1]=b[i];
                a[x+1]=a[x];
                a[x]+=y;
                n++;
            }
        }
        else if(b[i]!=b[x])
        {
            long long y=(a[i]-a[i-1])-(a[x]-a[x-1]);
            if(y<0)
            {
                ans+=(y+a[x]-a[x-1]);
                b[x+1]=b[i];
                a[x+1]=a[x];
                a[x]+=y;
                n++;
            }
            else if(y==0)
            {
                ans+=a[x]-a[x-1];
                b[x]=b[i];
            }
            else
            {
                long long z;
                y=(a[i]-a[i-1]);
                b[x]=b[i];
                b[x-1]=b[i];
                for(long long j=x-1;j>=i;j--)
                {
                    if(j==i)
                    {
                        ans+=(a[x]-a[i]);
                        cout<<ans;
                        return 0;
                    }
                    if(a[x]-a[j-1]-y==0)
                    {
                        ans+=y;
                        b[j]=b[i];
                        a[j]=a[x];
                        n=j;
                        break;
                    }
                    else if(a[x]-a[j-1]-y>0)
                    {
                        ans+=y;
                        z=a[x]-a[j-1];
                        y-=z;
                        a[j]+=y;
                        a[j+1]=a[x];
                        b[j+1]=b[i];
                        n=j+1;
                        break;
                    }
                    b[j]=b[i];
                }
            }
        }
        cout<<(n+1)/2<<" "<<i<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
