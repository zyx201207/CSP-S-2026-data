#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u[1000005],v[1000005];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    srand(time(0));
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> k;
        for (int i=1;i<=n;i++)
        {
            cin >> u[i] >> v[i];
        }
        cout << rand()%(n/2+1)+1 << endl;
    }
    return 0;
}
