#include <bits/stdc++.h>
using namespace std;
long long n,m,a[2000000];
int main()
{

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n >> m;
    for(int i = 1; i <= n; i++)
    {

        cin >> a[i];
    }
    cout << a[n];
    return 0;
}
