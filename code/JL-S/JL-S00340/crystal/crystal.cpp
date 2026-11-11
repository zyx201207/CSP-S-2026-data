#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=514514;
int n,m,a[N],sum,last,x,ans;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    a[n+1]=a[n]-1;
    x=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i+1])continue;
        sum+=(a[i]-a[last])*(last-x+1);
        while(sum>m)
        {
            sum-=a[i]-a[x];
            x++;
        }
        last=i;
        ans=max(ans,i-x+1);
    }
    cout<<ans;
    return 0;
}
