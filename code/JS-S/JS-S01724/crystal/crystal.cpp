#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m;
long long a[N];
long long sub[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long maxn=0;
    long long sum=0;
    long long cnt=0;
    long long j=n;
    for(long long i=n;i>=1;i--)
    {
        if(sum+a[n]-a[i]>m)
        {
            break;
        }
        sum+=a[n]-a[i];
        cnt++;
        j--;
    }
    maxn=max(maxn,cnt);
    for(long long i=n-1;i>=1;i--)
    {
        cnt--;
        sum-=cnt*(a[i+1]-a[i]);
        while(j>=1)
        {
            if(sum+a[i]-a[j]>m)
            {
                break;
            }
            sum+=a[i]-a[j];
            cnt++;
            j--;
        }
        maxn=max(maxn,cnt);
    }
    cout<<maxn;
    return 0;
}
