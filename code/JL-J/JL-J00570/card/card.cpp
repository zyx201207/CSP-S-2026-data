#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt[500005],ans[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int num=n+1;
    while(n--)
    {
        for(int i=num-n;i<=n;i++)
            cnt[a[i]]++;
        for(int i=num-n;i<=n;i++)
            if(cnt[a[i]]==1)ans[a[i]]++;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[a[i]]<<" ";
    return 0;
}
