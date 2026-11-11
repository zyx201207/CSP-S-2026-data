#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    if(n<=16)
    {
        long long a[20],b[20],c,ans=-1;
        for(long long i=1;i<=n;i++)
            cin>>a[i];
        for(long long i=1;i<=n;i++)
            for(long long j=i+1;j<=n;j++)
                if(a[j]<a[i])
                {
                    c=a[i];
                    a[i]=a[j];
                    a[j]=c;
                }
        for(long long i=1;i<=n-1;i++)
            b[i]=a[i+1]-a[i];
        for(long long i=1;i<=n-1;i++)
        {
            c=m;
            long long j=i,sum=1;
            c=c-b[i];
            while(c>=0&&j<=n-1)
            {
                sum++;
                c-=b[j+1];
                for(long long k=1;k<=j-i;k++)
                    c-=b[j];
                j++;
            }
            ans=max(ans,sum);
        }
        cout<<ans;
    }
    if(n>16)
    {
        long long a,b,c,ans=0;
        cin>>a>>b;
        for(long long i=2;i<n;i++)
            cin>>c;
        c=a-b;
        c=abs(c);
        long long k=0;
        while(ans<=n&&m>=0)
        {   m=m-k*c;
            if(m>=0)
                ans++;
            k++;
        }
        cout<<ans;
    }
    return 0;
}
