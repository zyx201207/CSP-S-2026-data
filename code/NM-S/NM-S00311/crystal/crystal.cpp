#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin >> n >>m;
    int a[n];
    for(int i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n;i++)
    {
        cout << a[i];
    }
    int sum = 0;

    for(int i = 1;i <= 5000000;i++)
    {
        sum += i;
        if(sum >= m)
        {
            cout << i + 1;
            break;
        }
    }
    return 0;
}
