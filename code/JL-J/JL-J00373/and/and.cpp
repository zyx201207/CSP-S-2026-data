#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,sum = 0,t;
    cin >> n >> m;
    int a[n + 5];


    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int b[10000];

    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            b[i] = a[i] | a[j];
        }
    }

    sort(b + 1, b + 1 + n);

    for(int i = 1; i <= n; i++)
    {
        sum = max(b[i], b[i + 1]);
    }
    cout << sum;

    if(m == 1)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(a[i + 1] > a[i])
                {
                    t = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = a[i];
                }
            }
            cout << a[i];
        }

        return 0;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
