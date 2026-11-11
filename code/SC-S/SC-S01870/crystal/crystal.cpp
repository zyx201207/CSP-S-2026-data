#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,ans=0;
ll m,a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int i=1;
    ll sum=0;
    for (int j=1;j<=n;j++)
    {
        sum+=(a[j]-a[j-1])*(j-i);
        while (sum>m)
        {
            sum-=a[j]-a[i];
            i++;
        }
        ans=max(ans,j-i+1);
    }
    cout<<ans;
    return 0;
}
