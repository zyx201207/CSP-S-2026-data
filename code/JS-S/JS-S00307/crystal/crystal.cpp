#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],cnt[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long ans=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        cnt[i]=(a[i]-a[i-1])*(i-1)+cnt[i-1];
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]<=m)
        {
            ans=i;
        }
    }
    cout<<ans;
    return 0;
}
