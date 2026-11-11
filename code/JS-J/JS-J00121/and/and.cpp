#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    long long n , m , maxn = 0;
    cin >> n >> m;
    long long a[100000 + 10];
    for (int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        maxn = max(maxn , a[i]);
    }
    m -= 1;
    while (m--)
    {
        for (int i = 0 ; i < n ; i++)
        {
            if (a[i] == maxn) 
            {
                a[i] = 0;
                maxn = 0;
            }
        }
        for (int i = 0 ; i < n ; i++)
        {
            maxn = max(maxn , a[i]);
        }
    }
    cout << maxn;
    return 0;
}
