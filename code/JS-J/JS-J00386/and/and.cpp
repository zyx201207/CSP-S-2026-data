#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[200005];

int main()
{
    freopen("and.cpp" , "r" , "stdin");
    freopen("and.cpp" , "w" , "stdout");
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long ans = -1;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    for(int i = n;i > n - m;i--)
    {
        if(i == n)
        {
            ans = a[i];
        }
        else
        {
            ans &= a[i];
        }
    }
    cout << ans;
    return 0;
}

