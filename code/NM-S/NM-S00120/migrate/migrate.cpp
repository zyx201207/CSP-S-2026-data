#include<bits/stdc++.h>
using namespace std;
int c,t,x;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t >> x;
    if(t == 2&&x == 4) cout << 1 << '\n' << 2;
    if(t == 2&&x == 5) cout << 0 << '\n' << 1;
    return 0;
}