#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+5;
int a[MAXN];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=1,cnt=0,ans=-1;
    while(r<=n)
    {
        if(m>=cnt)
        {
            ans=max(ans,r-l+1);
            r++;
            cnt+=(a[r]-a[r-1])*(r-l);
        }
        else
        {
            cnt-=(a[r]-a[l]);
            l++;
        }
    }
    cout<<ans;
    return 0;
}
