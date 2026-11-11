#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , m;
ll a[500010];
bool ck(int mid)
{
    for(int i = mid ; i <= n ; i++)
    {
        ll sum = 0;
        for(int j = i - mid + 1 ; j < i ; j++)
        {
            sum += a[i] - a[j];
        }
        if(sum <= m)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);
    cin >> n >> m;
    bool flag = true;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        if(a[i] != i)
        {
            flag = false;
        }
    }
    if(flag == true)
    {
        int sum = 0 , i = 1;
        while(sum <= m)
        {
            sum += i;
            i++;
        }
        cout << i - 1;
        return 0;
    }
    sort(a + 1 , a + n + 1);
    int l = 1 , r = n , ans;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(ck(mid) == 1)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
