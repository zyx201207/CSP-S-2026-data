#include <bits/stdc++.h>
using namespace std;
string a;
int main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);

    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int x;
        string b;
        cin >> x >> b;
        for(int j = 1;j <= x;j++)
        {
            a += b;
        }
    }

    int num = 0;

    for(int i = 0;i < a.length() / 2;i++)
    {
        if(a[i] != a[a.length() - i - 1])
        {
            num++;
        }
    }
    cout << num;


    return 0;
}
