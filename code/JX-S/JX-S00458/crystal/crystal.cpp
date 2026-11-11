#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,sum,ans,a[N];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    int i=1,j=2;
    sum=a[2]-a[1];
    while(i<j)
    {
        if(j==n&&sum<m)
        {
            ans=max(j-i+1,ans);
            break;
        }
        while(sum>m)
        {
            i++;
            sum-=(a[j]-a[i]);
            if(j==n&&sum<m)
                break;
        }
        ans=max(j-i+1,ans);
        if(j<n)
            j++;
        sum+=(j-i)*(a[j]-a[j-1]);

    }
    cout<<ans;
    return 0;
}
