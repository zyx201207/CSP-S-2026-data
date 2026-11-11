#include <bits/stdc++.h>
using namespace std;

string c1 , c2 , s1 , s2;

int code1 , code2;
int seat1 , seat2;


int main()
{

    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);

    cin >> c1 >> s1 >> c2 >> s2;

    code1 = (s1[0] - '0') * 10 + (s1[1] - '0');
    code2 = (s2[0] - '0') * 10 + (s2[1] - '0');

    seat1 = s1[2] - 'A';
    seat2 = s2[2] - 'A';

    if(c1 == c2)
    {

        cout << 1;

        if(code1 == code2)
        {
            cout << 1;

            if(seat1 + seat2 == 7)
            {
                cout << "11";
            }
            else if(seat1 == 3 || seat2 == 3 || seat1 == 4 || seat2 == 4)
            {
                cout << "00";
            }
            else
            {
                cout << 1;

                if(abs(seat1 - seat2) == 1)
                {
                    cout << 1;
                }
                else
                {
                    cout << 0;
                }
            }

        }
        else
        {
            cout << "000";
        }

    }
    else
    {
        cout << "0000";
    }







    return 0;


}
