#include <bits/stdc++.h>
#include <cstdio>
#define int long long
using namespace std;

const int N=5e5+10;
int n,arr[N],brr[N],m;

bool check(int k)
{
    int sum=0;
    for(int i=2;i<k;i++)
    {
        sum+=brr[i]*(i-1);
    }
    for(int i=k;i<=n;i++)
    {
        sum+=brr[i]*(k-1);
        if(sum<=m)  return true;
        sum-=(arr[i]-arr[i-k+1]);
    }
    return false;
}

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>arr[i];
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++)   brr[i]=arr[i]-arr[i-1];
    //for(int i=1;i<=n;i++)   cout<<(check(i)?"T":"F")<<endl;

    int l=1,r=n,ans=1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
