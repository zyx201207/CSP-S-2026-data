#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,a[N],ans[N],m,jp[N],b[N];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) b[a[i]]=i;
    for(int i=1;i<=n;i++) jp[i]=b[a[i]];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(jp[j]!=j) j=jp[j]-1;
            else ans[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
