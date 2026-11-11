#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int a = 0;
    for (int b = 29; b >= 0; b--)
    {
        int and = a | (1 << b);
        int c = 0;
        for (int i = 1; i <= n;i++)
        {
            if ((a[i] & and) == and)
            {
                c++;
            }
	}
    }
    if (c >= m)
    {
        a = and;
    }
    cout << a;
}


