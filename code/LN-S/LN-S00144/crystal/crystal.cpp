#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n , m , a[N] , d[N] , pos , ans , sum , i;
int main()
{
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" ,stdout);
    ios::sync_with_stdio(0);
    cin.tie(0) , cout.tie(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    sort(a + 1 , a + 1 + n);
    for(int i = 2 ; i <= n ; i++)
    {
        d[i - 1] = a[i] - a[i - 1];
    }
    for(i = 1 ; i <= n - 1 ;)
    {
        sum += d[i];
        if((sum > m) || (sum == m && d[i + 1] != 0))
        {
            sum = 0;
            ans = max(ans , i - pos);
            i = ++pos;
        }
        else
        {
            i++;
        }
    }
    ans = max(ans , i - pos);
    cout << ans;
    return 0;
}

