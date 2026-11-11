#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    string a,b,c;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++)
    {
        b[i] = 0;
    }
    for(int i = 1; i <= n; i++)
    {

        for(int j = i; j <= n; j++)
        {
            c[j] = a[j];
            for(int k = i; k <= j; k++)
            {
                if(c[k] == c[j])
                {
                    for(int l = k; l <= j; l++)
                    {
                        c[l] = 0;
                    }
                }
            }
        }
        for(int j = 1; j <= m; j++)
        {
            for(int k = i; k <= n; k++)
            {
                if(c[k] == j) b[j]++;
            }
        }
    }
    for(int i = 1; i <= m; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
