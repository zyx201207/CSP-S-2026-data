#include <bits/stdc++.h>
using namespace std;
const int N = 50;
char c1[N],c2[N],s1[N],s2[N];
bool is_side(char a,char b)
{
    if (a >= 'A' && a <= 'C' &&  b >= 'A' && b  <= 'C')
    {
        return true;
    }
    if (a >= 'D' && a <= 'E' && b >= 'D' && b <= 'E')
    {
        return true;
    }
    return false;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1>> s1 >> c2 >> s2;
    int numc1 = 0,numc2 = 0;
    for (int i = 0;i < strlen(c1);i ++)
    {
        numc1 = numc1 * 10 + c1[i] - '0';
        //cout << c1[i] - '0' << ';' << endl;
    }
    for (int i = 0;i < strlen(c2);i ++)
    {
        numc2 = numc2 * 10 + c2[i] - '0';
    }
    //cout << is_side('A','E') << endl;
    //cout << numc1 <<' ' << numc2 << endl;
    if (numc1 == numc2)
    {
        cout << '1';
        int k1,k2;
        k1 = (s1[0] - '0') * 10 + s1[1] - '0';
        k2 = (s2[0] - '0') *10 + s2[1] - '0';
        //cout << k1 << ' ' << k2<< endl;
        if (k1 == k2)
        {
            cout << '1';
            if (is_side(s1[2],s2[2]))
            {
                cout << '1';
                if (abs((s2[2] - 'A') - (s1[2] - 'A')) == 1)
                {
                    cout << '1';
                }
                else
                {
                    cout << '0';
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
