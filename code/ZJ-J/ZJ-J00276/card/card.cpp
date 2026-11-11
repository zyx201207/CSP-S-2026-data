#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> id(m+1);
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        id[a[i]].emplace_back(i);
    }
    vector<int> ans(m+1);
    for(int i=1;i<=n;++i)
    {
        for(int j=i;j<=n;++j)
        {
            if(j==id[a[j]].back()) ans[a[j]]++;
            else
            {
                int idx=upper_bound(id[a[j]].begin(),id[a[j]].end(),j)-id[a[j]].begin();
                j=id[a[j]][idx]-1;
            }
        }
    }
    for(int i=1;i<=m;++i) cout<<ans[i]<<' ';
}