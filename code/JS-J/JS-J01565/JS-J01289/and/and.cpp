#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m;
ll a[200005];
ll dp[200005];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int maxn;
    for(int i=1;i<=n-m;++i)
    {

        for(int j=i+m;j<=n;++j)
        {
            int ans=a[i];
            for(int k=i;k<=j;++k)
            {
                ans&=a[k];

            }
            maxn=max(maxn,ans);
        }
    }
    cout<<maxn;
    return 0;
}
