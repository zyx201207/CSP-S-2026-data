#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
char n1[6] = {'A','B','C','B','D','F'};
char n2[6] = {'B','A','B','C','F','D'};

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin.tie(0);

    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        cout << "1";
    }
    else
    {
        cout << "0000";
        return 0;
    }

    if ((s1[0] + s1[1]) == (s2[0] + s2[1]))
    {
        cout << "1";
    }
    else
    {
        cout << "000";
        return 0;
    }

    if (!((('A' <= s1[2]) && (s1[2] <= 'C')) ^ (('A' <= s2[2]) && (s2[2] <= 'C')) ))
    {
        cout << "1";
    }
    else
    {
        cout << "00";
        return 0;
    }

    for (int i = 0; i < 6; i++)
    {
        if ((s1[2] == n1[i]) && (s2[2] == n2[i]))
        {

            cout << "1";
            return 0;
        }
    }

    cout << "0";
    return 0;
}

