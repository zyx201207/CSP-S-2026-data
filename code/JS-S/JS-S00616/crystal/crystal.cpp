#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=-1;
long long arr[5000005]={0};
long long le[5000005]={0};
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    for(long long i=1;i<=n;i++)
    {
        le[i]=arr[i]+le[i-1];
    }
    for(long long i=1;i<=n;i++)
    {
        long long t=1;
        long long l=1,r=i-1;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            long long g=arr[i]*(i-mid)-le[i-1]+le[mid-1];
            if(g>m)
            l=mid+1;
            else{r=mid-1;
                t=max(t,i-mid+1);

            }
        }
        maxn=max(maxn,t);
    }
    cout<<maxn;
    return 0;
}
