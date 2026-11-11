#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
long long ans=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(m-i>=0)
        {
            m-=i;
            ans++;
        }
        else
        {
            ans=max(ans,m+1);
        }
    }
    cout<<ans;
    return 0;
}
