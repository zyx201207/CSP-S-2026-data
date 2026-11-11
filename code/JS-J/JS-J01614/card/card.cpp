#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500001];
int vis[300001];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin>>n>>m;
    cout<<n/2+n%2;
    return 0;
}
