#include <iostream>
#include <string>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c, cc; string s, ss;
    cin >> c >> s >> cc >> ss;
    if (c == cc)
    {
        cout << "1" ;
        if (s.substr(0, 2) == ss.substr(0, 2))
        {
            cout << "1" ;
            char o = s[2], oo = ss[2];
            if (o > oo) swap(o, oo);
            if (o=='A'&&oo=='B'||o=='A'&&oo=='C'||o=='B'&&oo=='C'||o=='D'&&oo=='F')
            {
                cout << "1" ;
                if (!(o=='A'&&oo=='C'))
                    cout << "1" ;
                else cout << "0";
            }
            else cout << "10";
        }
        else cout << "000" ;
    }
    else cout << "0000" ;
    cout << '\n';
    return 0;
}
