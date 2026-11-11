#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string sa, sb, a, b;
    cin >> sa >> a >> sb >> b;
    if(sa == sb)
    {
        cout << "1";
        string ta = "", tb = "";
        for(int i = 0; i < 2; i++)
        {
            ta += a[i];
            tb += b[i];
        }
        if(ta == tb)
        {
            cout << "1";
            bool f = 0;
            if(a[2] == 'C' && b[2] == 'D')  f = 0;
            else if(a[2] == 'D' && b[2] == 'C') f = 0;
            else if((a[2] == 'A' || 'B' || 'C') && (b[2] == 'A' || 'B' || 'C')) f = 1;
            else if((a[2] == 'D' || 'F') && (b[2] == 'D' || 'F')) f = 1;
            if(f == 1)
            {
                cout << "1";

                if(abs(int(a[2]) - int(b[2])) == 1 )
                {
                    cout << "1";
                    return 0;
                }
                else
                {
                    cout << "0";
                    return 0;
                }
            }
            else
            {
                cout << "00";
                return 0;
            }
        }
        else
        {
            cout << "000";
            return 0;
        }
    }
    else
    {
        cout << "0000";
        return 0;
    }
    return 0;
}
