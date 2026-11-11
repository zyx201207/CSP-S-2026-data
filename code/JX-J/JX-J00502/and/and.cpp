#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n , x;
    cin >> n >> x;
    int a[100001];
    int m[100001];
    int mx = -1;
    int b = 1;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    for (int i = 1 ; i <= n ; i++)
    {
        for(int j = i+1 ; j <= n ; j++)
        {
            m[b] += j&i;
            b++;
        }
    }

    for (int i = 1 ; i <= 1000 ; i++)
    {
        mx = max(mx , m[i]);
    }
    cout << mx;
    return 0;
}
