#include <bits/stdc++.h>
using namespace std;
long long w[500005];
long long mp[505][50005],t[5005][5005];
vector<vector<int>> s(500005);

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,n,m,d,p;
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            long long st,ti;
            cin>>st>>ti;
            mp[i][st]=ti;
            s[st].push_back(ti);
        }
    }
    for(int i=1;i<=m;i++)
    {

    }
    return 0;
}
