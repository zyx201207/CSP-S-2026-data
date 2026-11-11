#include <bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>c[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[n-i+1]&&c[i]!=c[n-i+1])
        {
            cnt+=a[i];
            continue;
        }
        else if(a[i]<=a[n-i+1]&&c[i]==c[n-i+1]&&c[i+1]==c[i]&&c[n-i]!=c[i+1])
        {
            cnt+=min(a[i]+a[i+1]-a[n-i+1],a[n-i]);
            continue;
        }
        else if(a[i]>=a[n-i+1]&&c[i]==c[n-i+1]&&c[n-i]==c[n-i+1]&&c[n-i]==c[i])
        {
            cnt+=min(a[i],a[n-i+1]+a[n-i]);
            continue;
        }
        else if(a[i]!=a[n-i+1]&&c[i]==c[n-i+1]&&c[i+1]!=c[i]&&c[n-i]!=c[i+1])
        {
            cnt+=min(a[i],a[n-i+1]);
            continue;
        }
        else if(a[i]!=a[n-i+1]&&c[i]!=c[n-i+1])
        {
            cnt+=min(a[i],a[n-i+1]);
            continue;
        }
    }
    if(cnt>=10000000)
    {
        cnt=(cnt+1)/2;
    }
    cout<<cnt;
    return 0;
}
