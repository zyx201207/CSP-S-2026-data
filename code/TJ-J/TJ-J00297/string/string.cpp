#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char b[200005];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    int i=1,j=n,ans=0;
    while(i<=j)
    {
        if(b[i]!=b[j]) ans+=min(a[i],a[j]);
        int xx=min(a[i],a[j]);
        a[i]-=xx;
        a[j]-=xx;

        //cerr<<i<<" "<<j<<" "<<a[i]<<" "<<a[j]<<" "<<b[i]<<" "<<b[j]<<" "<<ans<<"\n";
        if(a[i]<=0)
        {
            i++;
        }
        if(a[j]<=0)
        {
            j--;
        }
    }
    cout<<ans;
    return 0;
}
