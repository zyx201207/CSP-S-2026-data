#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main()
{
    freopon("/home/noi/桌面/kaoshi/TJ-J01486/travel/travel.in","r",stdin);
    freopen("/home/noi/桌面/kaoshi/TJ-J01486/travel/travel.out","w",stdout);
    int c1, c2;
    string s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool a1 = (c1 == c2)
    cout << a1;
    bool a2 = true;
    for(int i = 0;i < 2;i++)
    {
        if(s1[i] != s2[i])
        {
            a2 = false;
            break;
        }
    }
    cout << a2;
    char b1 = s1[2];
    char b2 = s2[2];
    if(b1 >= 'A' && b1 <= 'C' && b2 >= 'A' && b2 <= 'C')
    {
        cout << "1";
        if(abs(b1 - b2) == 1) cout << "1";
        else cout << "0";
    }
    else if(b1 >= 'D' && b1 <= 'F' && b2 >= 'D' && b2 <= 'F')
    {
        cout << "1";
        if(abs(b1-b2) == 2) cout << "1";
        else cout << "0";
    }
    else cout << "00";
    fclose(stdin);
    fcloses(stdout);
    return 0;
}
/*
02 01A 02 01B

*/
