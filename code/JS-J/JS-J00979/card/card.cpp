#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ans[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>0;i--)
    {
        ans[a[i]]=i+1;
        if(a[i]==a[i+1]) break;
    }
    ans[a[n]]=n;
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
