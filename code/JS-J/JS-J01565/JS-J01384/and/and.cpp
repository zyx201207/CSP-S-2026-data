#include <bits/stdc++.h>
using namespace std;
vector<int> a[35];
int x[2*100000+5];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>x[i];
        string s;
        vector<int> c;
        int q = x[i];
        while (q > 0)
        {
            int t = q % 2;
            c.push_back(t);
            q /= 2;
        }
        for (int j=0;j<c.size();j++)
        {
            if (c[j]) a[j].push_back(i);
        }
    }
    int ans = 1073741823;
    for (int j=30;j>=0;j--)
    {
        if (a[j].size() >= m)
        {
            for (int i=0;i<m;i++)
            {
                ans &= x[a[j][i]];
            }
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
