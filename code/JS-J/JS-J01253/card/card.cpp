#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long cnt[300005];
long long ans[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int q=1;q<=n;q++)
    {
        cin>>a[q];
        cnt[a[q]]++;
    }
    for(int q=1;q<=n;q++)
    {
        cnt[a[q-1]]-=1;
        if(cnt[a[q-1]]==0)
        {
            ans[a[q-1]]=q-1;
        }
    }
    for(int q=1;q<=m;q++)
    {
        if(ans[m]==0)
        {
            ans[m]=n;
        }
        cout<<ans[q]<<" ";
    }
    return 0;
}
