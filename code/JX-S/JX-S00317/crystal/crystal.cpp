#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    long long sum=0,j=1;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        while(a[i]*(i-j+1)-sum>m)
        {
            sum-=a[j];
            j++;
        }
        ans=max(ans,i-j+1);
    }
    cout <<ans;
    return 0;
}
