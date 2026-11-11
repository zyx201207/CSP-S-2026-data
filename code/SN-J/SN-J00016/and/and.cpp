#include <bits/stdc++.h>
using namespace std;

int n , m,a[200005],d;
void b(int x , int y)
{
    if(x > 0)
    {
        for(int j = y;j < n;j++)
        {
            m--;
            b(m,j);
        }
    }
    else
    {
        d = a[j] & a[y];
        for(int j = y;j < n;j++)
        {
            if(a[j + 1] & a[y] > d)
            {
                d = a[j + 1] & a[y];
            }
        }
        a[y] = d;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    for(int i = 0;i < n;i++)
    {
        m--;
        b(m,i);
    }
    cout << d;
    return 0;
}
