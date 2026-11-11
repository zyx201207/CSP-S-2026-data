#include <bits/stdc++.h>
using namespace std;
int a[500000];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,cnt = 0,s = 0;
    cin >> n >> m;
    for(int i = 0;i < n;i++)cin >>a[i];
    sort(a,a+n);
    long long x = a[1] - a[0];
    while(1)
    {
        m -= x * s;
        if(m < 0)break;
        cnt++;
        s++;
    }
    cout << cnt;
    return 0;
}
