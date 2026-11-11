#include<bits/stdc++.h>
using namespace std;
int n;
long long m,maxx=1;
long long a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    a[0]=1e18;
    a[n+1]=-1e18;
    if(n<=5000)
    {
        for(int i=n;i>=2;i--)
        {
            int l=i-1;
            long long ans=1,sum=0;
            while(l>0&&ans<n)
            {
                if(sum+abs(a[l]-a[i])>m)break;
                sum+=abs(a[l]-a[i]);
                ans++;
                l--;
            }
            maxx=max(ans,maxx);
        }
        cout<<maxx;
        return 0;
    }
    int i=n;
    int l=i-1;
    long long ans=1,sum=0;
    while(l>0&&ans<n)
    {
        if(sum+abs(a[l]-a[i])>m)break;
        sum+=abs(a[l]-a[i]);
        ans++;
        l--;
    }
    cout<<ans;
    return 0;
}
