#include <bits/stdc++.h>
using namespace std;
int n,x1,sum = 0,num = 0;
string s = "",x;
int main()
{
    freopen ("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> x1 >> x;
        sum += x1;
        for (int i = 1;i <= x1;i++)
        {
            s += x;
        }
    }
    for (int i = 0;i < sum/2;i++)
    {
        if (s[i] != s[sum-i-1])
        {

            num++;
        }
    }
    cout << num;
    return 0;
}
