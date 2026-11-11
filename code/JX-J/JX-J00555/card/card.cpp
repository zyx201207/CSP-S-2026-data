#include <bits/stdc++.h>
using namespace std;

int card[300025],a[300025],b[300025],c[300025];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> card[i];
    }
    for(int i = 1;i <= n;i++)
    {
        int cmp = i;
        for(int j = i;j <= n;j++)
        {
            a[j] = card[j];
            for(int k = i;k < j;k++)
            {
                if(a[k] == a[j]) cmp = j;
            }
        }
        for(int j = cmp;j <= n;j++)
        {
            c[a[j]]++;
        }
    }
    for(int i = 1;i <= m;i++)
    {
        cout << c[i] << " ";
    }
    return 0;
    }

