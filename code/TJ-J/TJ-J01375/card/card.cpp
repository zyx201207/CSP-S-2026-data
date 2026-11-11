#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>

using namespace std;

int n, m, a[500005], b[300005];
vector<int> temp;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    cout << 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = 0; k < j; k++)
            {
                if (temp[k] == a[j])
                {
                    for (int l = k; l < temp.size(); l++)
                    {
                        temp.pop_back();
                    }
                }
                temp.push_back(a[j]);
            }

            for (int j = 0; j < temp.size(); j++)
            {
                b[temp[temp.size() - 1]]++;
                temp.pop_back();
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        printf("%d", b[i]);
    }

    return 0;
}