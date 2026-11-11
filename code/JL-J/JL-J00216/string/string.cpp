#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in""r",stdin);
    freopen("string.out""w",stdout);
    string b,c;
    int n,a,sum = 0;
    cin >>n;
     for(int i = 0;i<n;i++)
    {
        cin >>a;
        sum+=a;
        cin >>c[i];
        for(int j = 0;j<a;j++)
        {
            b+=c[i];
        }
    }
    for(int i = 0;i<sum;i++)
    {
        if(b[i]!=b[sum-i])
        {
            b[sum-i] = b[i];
        }
    }
    for(int i = 0;i<n;i++)
    {
         cout << b[i];
    }
    return 0;
}
