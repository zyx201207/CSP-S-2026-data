#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500001]={},cnt[500001]={},ans=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=2;i<=n;i++)
    {
        if(m-(a[i]-a[i-1])*(i-1)>=0)
        {
            ans++;
            m-=(a[i]-a[i-1])*(i-1);
        }
    }
    cout<<ans;
    return 0;
}
