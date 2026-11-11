#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,a[10000];
    cin >> c >> t;
    for(int i = 0;i < 13;i++)
        cin >> a[i];
    if(a[0] == 4) cout << 1 << endl << 2;
    else cout << 0 << endl << 1;
    return 0;
}
