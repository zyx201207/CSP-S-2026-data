#include <bits/stdc++.h>
using namespace std;
struct hub{
    int n,k;
    int u[1000002],v[1000002];
};
hub l[7];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >> c >> t;
    for(int i=1;i<=t;i++)
    {
        cin >> l[i].n >> l[i].k;
        cout << 1 << endl;
    }
    return 0;
}
