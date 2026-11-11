#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n;
long long m;
vector <long long> v;
long long d=0;
int l=1;
int ans=1;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        long long x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(int i=1;i<n;i++)
    {
        l++;
        d+=(l-1)*(v[i]-v[i-1]);
        while(d>m)
        {
            d-=(v[i]-v[i-l+1]);
            l--;
        }
        ans=max(ans,l);
    }
    cout<<ans<<"\n";
    return 0;
}
