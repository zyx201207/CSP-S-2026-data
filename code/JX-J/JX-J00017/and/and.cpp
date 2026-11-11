#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[100],b[100],sum = -1;
    bool qwq = 1;
    cin >> n >> m;
    for (int i = 1 ;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i =1;i <= n;i++)
    {
        for (int j = i;j <= m+i-1;j++)
        {
            b[j] = a[j]&a[j+1];
            if (b[j] > sum)
            {
                sum = b[i];
            }
        }
    }
    cout <<sum;
    return 0;
}
