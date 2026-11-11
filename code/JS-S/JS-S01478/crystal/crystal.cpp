#include<bits/stdc++.h>
using namespace std;
const int Mx=5e5+15;
int n;
long long m,Max;
long long arr[Mx],cnt[Mx];
long long ad(int i,int j)
{
    if(i>j) swap(i,j);
    return cnt[j]-cnt[i-1]-(j-i+1)*(Max-arr[i]);
}
int main()
{
    freopen("crystal.in","r",stdin);

    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+n+1);
    reverse(arr+1,arr+n+1);
    Max=arr[n];
    for(int i=1;i<=n;i++)
    {
        cnt[i]=Max-arr[i];
    }

    for(int i=1;i<=n;i++)
    {
        cnt[i]+=cnt[i-1];
    }
    int j=1,ans=0;
    for(int i=1;i<=n;i++)
    {
        while(j<i)
        {
            if(ad(j,i)>m) j++;
            else break;
        }
        if(ad(j,i)<=m)
        {
            ans=max(ans,i-j+1);
        }
    }
    cout<<ans;
    return 0;
}
