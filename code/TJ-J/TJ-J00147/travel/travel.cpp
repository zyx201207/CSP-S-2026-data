#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,cnt = 0;
    string s1;
    int c2;
    string s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) cout << 1;
    else cout << 0;
    for(int i = 1;i <= 2;i++)
    {
        string a = s1.substr(i-1,1),b = s2.substr(i-1,1);
        if(a == b) cnt++;
    }
    if(c1 == c2&&cnt == 2) cout << 1;
    else cout << 0;
    string a = s1.substr(2,1),b = s2.substr(2,1);
    if(c1 == c2&&cnt == 2&&a == "A"&&b == "B") cout << 11;
    else{
        if(c1 == c2&&cnt == 2&&a == "B"&&b == "A") cout << 11;
        else{
            if(c1 == c2&&cnt == 2&&a == "B"&&b == "C") cout << 11;
            else{
                if(c1 == c2&&cnt == 2&&a == "C"&&b == "B") cout << 11;
                else{
                    if(c1 == c2&&cnt == 2&&a == "D"&&b == "F") cout << 11;
                    else{
                        if(c1 == c2&&cnt == 2&&a == "F"&&b == "D") cout << 11;
                    }
                }
            }
        }
        cout << 00;
    }
    return 0;
}
