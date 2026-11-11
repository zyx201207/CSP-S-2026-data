#include<iostream>
using namespace std;
string c1 , z1 , z2 , c2;
int a , b;
int main()
{
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    cin >> c1 >> z1 >> c2 >> z2;
    if('A' <= z1[2] && z1[2] <= 'C')
    {
        a = 1;
    }
    if('A' <= z2[2] && z2[2] <= 'C')
    {
        b = 1;
    }
    if(c1 == c2)
    {
        cout << "1";
        if(z1[0] == z2[0] && z1[1] == z2[1])
        {
            cout << "1";
            if(a == b)
            {
                cout << "1";
                if(z1[2] + 1 == z2[2] || z2[2] + 1 == z1[2])
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
                cout << "00";
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
