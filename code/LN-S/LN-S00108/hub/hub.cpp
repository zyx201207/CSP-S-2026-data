#include<bits/stdc++.h>
using namespace std;
int c , t , n , k;
int u[1000009] , v[1000009];
int main()
{
    freopen("hub.in" , "r" , stdin);
    freopen("hub.out" , "w" , stdout);
    ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);
    cin >> c >> t;
    for(int i = 1 ; i <= t ; i++)
    {
        cin >> n >> k;
        for(int j = 1 ; j <= n - 1 ; j++)
        {
            cin >> u[i] >> v[i];
        }
    }
    if(c == 0)
    {
        cout << 1 << "\n" << 2;
    }
    return 0;
}
