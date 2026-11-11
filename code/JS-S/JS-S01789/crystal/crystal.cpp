#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m,a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    long long tot=0;
    int l=1;
    for(int r=2;r<=n;r++)
    {
        tot+=1ll*(r-l)*(a[r]-a[r-1]);
        while(l<=r&&tot>m)
        {
            tot-=(a[r]-a[l]);
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout << ans;
    return 0;
}
