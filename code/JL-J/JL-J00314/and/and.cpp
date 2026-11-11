#include<bits/stdc++.h>
using namespace std;
int n , m , a[200001] , ma = 0;
int main()
{
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }
    if(m == 1)
    {
        for(int i = 1;i <= n;i ++)
        {
            if(a[i] > ma)
            {
                ma = a[i];
            }
        }
        cout << ma;
    }
    else if(m == 2)
    {
        for(int i = 1;i <= n;i ++)
        {
            for(int j = i + 1;j <= n;j ++)
            {
                if(a[i] & a[j] > ma)
                {
                    ma = a[i] & a[j];
                }
            }
        }
        cout << ma;
    }
    else if(m == n)
    {
        for(int i = 1;i <= n;i ++)
        {
            ma = ma & a[i];
        }
        cout << ma;
    }
    else if(m == n - 1)
    {
        int mi = 100000 , w = 0;
        for(int i = 1;i <= n;i ++)
        {
            if(a[i] < mi)
            {
                mi = a[i];
                w = 1;
            }
        }
        for(int i = 1;i <= n;i ++)
        {
            if(w != i)
            {
                ma = ma & a[i];
            }
        }
    }
    else
    {
        cout << "0";
    }
    return 0;
}
