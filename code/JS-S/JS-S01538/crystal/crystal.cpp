#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[500005],s[500005];
ll n,m;

bool check(int targ,int start)
{
    ll opts=a[targ]*(targ-start)-(s[targ-1]-s[start-1]);
    return opts<=m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];

    int ans=1;
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i-1;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(check(i,mid)) r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans<<'\n';

    return 0;
}