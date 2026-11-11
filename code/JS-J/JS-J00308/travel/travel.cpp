#include <bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> ca >> sa >> cb >> sb;
    if (ca == cb)
    {
        cout << "1";
        if (sa[0] == sb[0] and sa[1] == sb[1])
        {
            cout << "1";
            if(sa[2] == 'A')
            {
                if (sb[2] == 'B' or sb[2] == 'C')
                {

                    cout << "1";
                    if (sb[2] == 'B')
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
            else if (sa[2] == 'B')
            {
                if (sb[2] == 'A' or sb[2] == 'C')
                {

                    cout << "11";
                }
            }
            else if (sa[2] == 'C')
            {
                if (sb[2] == 'B' or sb[2] == 'A')
                {

                    cout << "1";
                    if (sb[2] == 'B')
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
            else if(sa[2] == 'D')
            {
                if (sb[2] == 'F')
                {
                    cout << "11";
                }
                else
                {
                    cout << "00";
                }
            }
            else if(sa[2] == 'F')
            {
                if (sb[2] == 'D')
                {
                    cout << "11";
                }
                else
                {
                    cout << "00";
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
