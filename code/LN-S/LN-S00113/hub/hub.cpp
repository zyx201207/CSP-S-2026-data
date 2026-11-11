#include <bits/stdc++.h>
using namespace std;
long long u[1000005],v[1000005];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    long long c,t;
    cin >> c >> t;
    for(int i = 0;i < n;i++)cin >> u[i] >> v[i];
    sort(u,u+n);
    sort(v,v+n);
    cout << u[0] << endl << v[0];
    return 0;
}
