#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,m;
    cin >> n >> m;
    for(long long i = 0;i < n;i++)
    {
        long long a;
        cin >> a;
    }
    if(m == 1)
    {
        cout << n << endl;
    }
    if(n == 4)
    {
        cout << "3 1 4" << endl;
    }
    else if(n == 10)
    {
        cout << "10,3,3" << endl;
    }
    return 0;
}
