#include <bits/stdc++.h>
using namespace std;

string idx1, idx2, str1, str2;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> idx1 >> str1 >> idx2 >> str2;
    int flag1 = 0;
    if (idx1 == idx2)
    {
        flag1 = 1;
        cout << "1";
    }
    else
    {
        cout << "0";
    }

    int flag2 = 0;
    if (flag1 == 1)
    {

        if (str1[0] == str2[0] && str1[1] == str2[1])
        {
            cout << "1";
            if ((str1[2] >= 'A' && str1[2] <= 'C') && (str2[2] >= 'A' && str2[2] <= 'C'))
            {
                flag2 = 1;
            }
            if ((str1[2] >= 'D' && str1[2] <= 'F') && (str2[2] >= 'D' && str2[2] <= 'F'))
            {
                flag2 = 1;
            }
        }
        else
        {
            cout << "0";
        }
    }
    else
    {
        cout << "0";
    }


    if (flag1 == 1)
    {
        if (flag2 == 1)
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
    else
    {
        cout << "0";
    }


    if (((str1[2] == 'C' && str2[2] == 'D') || (str1[2] == 'D' && str2[2] == 'C')) || flag1 == 0 || flag2 == 0)
    {
        cout << "0";
    }
    else
    {
        if (abs(str1[2] - str2[2]) == 1)
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
    return 0;
}
