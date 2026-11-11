#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n,m;
    cin >> n >> m;
    vector<int> a(n),ans(m,0);
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
        ans[a[i]]++;
    }
    for (int i=1;i<=m;i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}