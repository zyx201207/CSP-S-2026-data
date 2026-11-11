#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000010];
int ans[1000010];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<=m)
        {
            ans[a[i]]=max(ans[a[i]],i);
        }
    }
    for(int i=1;i<=m;i++)
    {

        cout<<ans[i]<<" ";
    }
    return 0;
}
