#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,c,d,q,sum;
ll w[100100];
void solve()
{
    cin>>c>>n>>m>>d>>q;
    for(ll i=1; i<=m; i++)
    {
        ll x;
        cin>>x;
        sum+=x;
    }
    cout<<sum;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    solve();
    return 0;
}
