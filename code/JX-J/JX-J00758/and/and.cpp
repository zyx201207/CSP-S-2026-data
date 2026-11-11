#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll x;
};
bool cmp(node a, node b)
{
    return a.x > b.x;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;
    ll k = m;
    vector<node> a(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x;
    }
    sort(a.begin(), a.end(), cmp);
    ll ans = a[1].x;
    for(int i = 0; i < k; i++)
    {
        ans &= a[i].x;
    }
    cout << ans << "\n";
    return 0;
}
