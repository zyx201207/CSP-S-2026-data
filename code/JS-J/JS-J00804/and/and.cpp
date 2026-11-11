#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end(),greater<ll>());
    cout << a[k-1];
    return 0;
}