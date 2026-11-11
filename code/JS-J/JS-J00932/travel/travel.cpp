#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,line1,line2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    line1 = s1[0] + s1[1];
    line2 = s2[0] + s2[1];
    int num1 = s1[2] - 'A',num2 = s2[2] - 'A';
    if(c1 == c2)
    {
        cout << 1;
        if(line1 == line2)
        {
            cout << 1;
            if((num1 <= 2 && num2 <= 2) || (num1 >= 3 && num2 >= 3))
            {
                cout << 1;
                if(num1 > num2) swap(num1,num2);
                if((num1 == 0 && num2 == 1) || (num1 == 1 && num2 == 2) || (num1 == 3 && num2 == 5))
                    cout << 1;
                else
                    cout << 0;
            }
            else
                cout << "00";
        }
        else
            cout << "000";
    }
    else
        cout << "0000";
}
