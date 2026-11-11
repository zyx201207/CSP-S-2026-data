#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n;
long long m;
long long a[N],sum[N],maxx,ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.in","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    for (int i=1;i<=n;i++)
    {
        maxx=a[i]*i-sum[i];
        if(maxx<=m)
        {
            ans=i;
        }
        else
            break;
    }
    cout<<ans;
    return 0;
}
