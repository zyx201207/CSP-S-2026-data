#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[j]=b[j];
        }
        long long x=m;
        for(int j=1;j<=n;j++)
        {
            long long y=a[i]-a[j];
            if(a[j]<a[i]&&y<=x&&x>=0)
            {
                a[j]=a[i];
                x-=y;
            }
        }
        long long cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j]==a[i])
            {
                cnt++;
            }
        }
        if(cnt>=ans)
        {
            ans=cnt;
        }
    }
    cout<<ans;
    return 0;
}
