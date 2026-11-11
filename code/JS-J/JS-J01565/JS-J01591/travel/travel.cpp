#include <bits/stdc++.h>
using namespace std;
string c1 , c2 , c3  , c4;
int main()
{
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    bool flag = false;
    cin >> c1 >> c2 >> c3 >> c4;
    if(c1 == c3)
    {
        cout << 1;
    }
    else
    {
        flag = true;
        cout << 0;
    }
    if(c2[0] == c4[0] && c2[1] == c4[1] && flag == false)
    {
        cout << 1;
    }
    else
    {
        flag = true;
        cout << 0;
    }
    if(((c2[2] - 'A' <= 2 && c4[2] - 'A' <= 2) || (c2[2] - 'A' > 2 && c4[2] - 'A' > 2)) && flag == false)
    {
        cout << 1;
    }
    else
    {
        flag = true;
        cout << 0;
    }
    if((c2[2] - 'A' <= 2 && c4[2] - 'A' <= 2) && (max(int(c2[2] - 'A') , int(c4[2] - 'A')) - min(int(c2[2] - 'A') , int(c4[2] - 'A')) == 1) && flag == false)
    {
        cout << 1;
    }
    else if(c2[2] - 'A' > 2 && c4[2] - 'A' > 2 && flag == false)
    {
        cout << 1;
    }
    else
    {
        flag = true;
        cout << 0;
    }
    return 0;
}
