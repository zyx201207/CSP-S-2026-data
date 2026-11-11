#include<bits/stdc++.h>
using namespace std;
long long a[500001];
long long s[500001];
long long n, m;
int bf(int i)
{
    //find a max(x) that x*a_i - s_i+s_i-x <= m
    int l = 0, r = i + 1;
    while(r - 1 > l)
    {
        int mid = (l + r) / 2;
        if((mid + 1) * a[i] - s[i] + s[i - mid] > m)
        {
            r = mid - 1;
        }
        else
        {
            l = mid;
        }
    }
    if(l * a[i] - s[i] + s[i - l] <= m)
    {
        return l;
    }
    else
    {
        return 1;
    }
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1;i <= n;i++)
    {
        s[i] = s[i - 1] + a[i];;
    }
    int lz = 1;
    for(int i = 1;i <= n;i ++)
    {
        lz = max(lz, bf(i));
    }
    cout << lz;
    return 0;
}
