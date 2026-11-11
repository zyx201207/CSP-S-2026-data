//kskbl wkzdjd
#include <bits/stdc++.h>
using namespace std;
int n,m,dp[500005],ed[300005],a[500005],ans[300005];
vector<int> s[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        s[a[i]].push_back(i);
        ed[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=1;
        if(ed[a[i-1]]==i-1) for(int j=0;j<s[a[i-1]].size();j++) dp[i]+=dp[s[a[i-1]][j]];
        ans[a[i]]+=dp[i];
    }
    for(int i=1;i<=m;i++) cout << ans[i] << ' ';
}
