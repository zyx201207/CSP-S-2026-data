#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[1000000001],sum = 0,num = 0,aum = 0,rum = 0;
    string b,c;
    a[0] = 0;
    cin >>n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        aum += a[i];
        cin >> b;
        for (int j = rum + 1;j <= aum;j++)
        {
            c[j] = b [0];
            sum++;
        }
        rum += a[i];
    }
    for(int i = 1;i <= sum;i++)
    {
        for (int j = sum;j >= 1;i--)
        {
            if(c[i] != c[j])
            {
                c[j] = c[i];
                num++;
            }
        }
    }
    cout << num;
    return 0;
}

