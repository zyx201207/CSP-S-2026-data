#include <bits/stdc++.h>
using namespace std;
int n,a[200005],sum,leng;
char c[200005];
string x,y;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        cin >> a[i] >> c[i];
        for(int j = 1;j <= a[i];j++)
        {
            x += c[i];
            leng++;
        }
    }
    for (int i = leng - 1;i >= 0;i--)
    {
        y += x[i];
    }
    if (x == y)
    {
        cout  << 0;
    }
    else
    {
        cout << n * 2 - 4;
    }
    return 0;
}
