#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;long long m;
    cin >> n >> m;
    cin >>a[1]>>a[2];
    bool f  =1;
    double w;
    for (int i = 3; i <= n; i++)
    {
        cin>>a[i];
        w = w+a[i] *1.0 / n;
        if (a[i]-a[i-1] != a[i-1]-a[i-2])   f=0;
    }
    if(f)
    {
        int t = a[2] - a[1];
        if (t!=1)   sort(a+1,a+1+n) ;
        long long sum = 0, i = 0;
        while (0 < m)
        {
            i++;
            sum+=t;
            m -= sum;
        }
        if (m <0) i--;
        cout << i+1;
    }
    else
    {
        sort(a + 1, a + 1 + n);
        w=(int)w;
        int t, k=2147483647;
        for (int i = 1; i <= n; i++)
        {
            if (abs(a[i]-w) > k)break;
            k = abs(a[i] - w);
            t = i;
        }
        int sum = 1;
        for (int i = t-1; i >= 1 && m >0;i--)
        {
            m-=a[i]-w;
            if(m>=0)sum++;
        }
        cout << sum;
    }
    return 0;
}
