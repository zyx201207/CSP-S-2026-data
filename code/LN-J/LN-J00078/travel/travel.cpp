#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,z1,z2;
    char s,x;
    bool t;
    t = true;
    cin >> c1 >> z1 >> c2 >> z2;
    s = c1[0];
    x = c2[0];
    if(s == x)
    {
        s = c1[1];
        x = c2[1];
        if(s == x)
        {

            cout << '1';
            s = z1[0];
            x = z2[0];

            if(s == x)
            {
                s = z1[1];
                x = z2[1];
                if(s == x)
                {
                    cout << '1';






                    s = z1[2];
                    x = z2[2];

                    if('A' <= s && 'C' >= s && 'A' <= x && 'C' >= x )
                    {
                        if(s == 'A' && x == 'B')
                        {
                            cout << '1' << '1';
                        }

                        else if(x == 'A' && s == 'B')
                        {
                            cout << '1' << '1';
                        }
                        else if(x == 'C' && s == 'B')
                        {
                            cout << '1' << '1';
                        }
                        else if(s == 'C' && x == 'B')
                        {
                            cout << '1' << '1';
                        }
                        else{
                            cout << '1' << '0';
                        }

                    }
                    else if('D' <= s && 'F' >= s && 'D' <= x && 'F' >= x )
                    {
                        cout << '1' << '1';

                    }
                    else
                    {
                        cout << '0' << '0';
                    }

                }
                else
                {
                    cout << '0' << '0' << '0';
                }
            }
        }
        else
        {
            cout << '0' << '0' << '0' << '0';
        }
    }


    return 0;
}
