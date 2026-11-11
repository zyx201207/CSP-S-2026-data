#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int main()
{
    freopen("and.in", "r",stdin);
    freopen("and.out", "w",stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    int maxx = 0;
    int num = a[0];
    for(int i = 0;i < n;i++)
    {
        if(maxx < a[i])
        {
            maxx = a[i];
        }
        num = num & a[i];
    }
    if(m == 1)
    {
        cout << maxx;
    }
    if(m == n)
    {
        cout << num;
    }
    int maxxx = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = i + 1;j < n;j++)
        {
            if(a[i] & a[j] > maxxx)
            {
                maxxx = a[i] & a[j];
            }
        }
    }
    if(m == 2)
    {
        cout << maxxx;
    }
    return 0;
}
