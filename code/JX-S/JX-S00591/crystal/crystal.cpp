#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long ans=0;
const long long N=INT_MAX;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    int flag=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int l=n;
    int r=1;
    int mid=(l-r)/2;
    long long maxn=-N;
    while(1)
    {
        long long t=a[mid+1];
        long long sum=m;
        for(int i=1;i<=mid;i++)
        {
            sum+=a[i];
        }
        ans=0;
        for(int i=mid+1;i<=n;i++)
        {
            if(a[i]!=t)break;
            ans++;
        }
        if(sum>t*mid)
        {
            ans+=mid;
            maxn=max(maxn,ans);
            r=mid;
            mid=mid+(l-r)/2;
        }
        else if(sum<t*mid){
            l=mid;
            mid=(l-r)/2;
        }
        if(l-1==r)
        {
            cout<<maxn;
            return 0;
        }
        if(sum==t*mid)
        {
            ans+=mid;
            cout<<ans;
            return 0;
        }
    }
    return 0;
}
