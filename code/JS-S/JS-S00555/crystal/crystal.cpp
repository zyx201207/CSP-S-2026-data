#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll s[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>s[i];
    sort(s+1,s+1+n);
    ll l=1,r=1,ans=1,nowm=0;
    while(l<=n)
    {
        if(r<n) r+=1;
        ll jia=(s[r]-s[r-1])*(r-l);
        nowm+=jia;
        if(nowm>m)
        {
            while(nowm>m)
            {
                l+=1;
                nowm-=s[r]-s[l];
            }
        }
        else
        {
            ans=max(ans,r-l+1);
        }
    }
    cout<<ans;
    return 0;
}
