#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,a[500001],max=0;
    cin >> n>> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for (int i = 1;i <= n;i++)
    {
        int sum = 0;
        for (int j = i;j >= 1;j--)
        {
            if (a[j] <= a[i] && m >= a[i] - a[j])
            {
                m -= a[i] - a[j];
                sum += 1;
            }
        }
        if (max < sum)
        {
            max = sum;
        }
    }
    cout<< max;
    return 0;
}
