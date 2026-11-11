#include <bits/stdc++.h>
using namespace std;
int a[500005],b[300005];
int main()
{

    freopen("card.in" , "r" , stdin);
    freopen("card,out", "w" , stdout);

    int n,m;
    cin >> n >> m;

    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }

    for(int i = 1;i <= n;i++)
    {
        int p = i;
        while(p <= n)
        {
            int ans = a[p];
            b[ans]++;
            for(int j = n;j > 1;j--)
            {
                if(a[j] == a[p] )
                {
                        p = j + 1;
                        break;
                }

            }

        }
    }

    for(int i = 1;i <= m;i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
