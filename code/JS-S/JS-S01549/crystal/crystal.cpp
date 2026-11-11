#include <bits/stdc++.h>
using namespace std;

const int N=5e5+10;
long long n,m;

long long a[N],b[N],dp[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);

    for(int i=1; i<n; i++)
    {
        b[i]=a[i+1]-a[i];
    }

    long long now=0,fir=1,ans=0,sum=0;
    for(int i=1; i<n; i++)
    {
        while(now>m)
        {
            now-=sum;
            sum-=b[fir];
            fir++;
        }
        now+=b[i]*(i-fir+1);
        sum+=b[i];
        ans=max(ans,i-fir+1);
    }
    cout<<ans;
    return 0;
}
