#include <iostream>
using namespace std;



int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,c1,s2,c2;
    cin >> s1 >> c1 >> s2 >> c2;
    char t1 = c1[2];
    char t2 = c2[2];
    string a1, a2;
    for (int i = 0; i < 2; i++)
    {
        a1 += c1[i];
        a2 += c2[i];
    }
    if (s1 == s2)
    {
        cout << 1;
        if (a1 == a2)
        {
            cout << 1;
            if ((((t1-'A'+1)-3)<=0 && ((t2-'A'+1)-3)<=0) || (((t1-'A'+1)-3)>0 && ((t2-'A'+1)-3)>0))
            {
                cout << 1;
                if (abs(t1-t2) == 1 || (t1 == 'D'&&t2 == 'F') || (t1 == 'F'&& t2 == 'D'))
                {
                    cout << 1;
                }
                else cout << 0;
            }
            else cout << "00";

        }
        else cout << "000";
    }
    else cout << "0000";

    return 0;
}
