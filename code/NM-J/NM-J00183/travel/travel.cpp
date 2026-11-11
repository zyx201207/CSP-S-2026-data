#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int a = (c1[0] - '0') * 10 + (c1[1] - '0');
    int b = (c2[0] - '0') * 10 + (c2[1] - '0');
    if(a == b)
    {
        cout << 1;
    }
    else{
        cout << 0 << 0 << 0 << 0;
        return 0;
    }
    int c = (s1[0] - '0') * 10 + (s1[1] - '0');
    int d = (s2[0] - '0') * 10 + (s2[1] - '0');
    if(c == d)
    {
        cout << 1;
    }
    else{
        cout << 0 << 0 << 0;
        return 0;
    }
    int e = (s1[2] - 'A') + 1;
    int f = (s2[2] - 'A') + 1;
    if((e <= 3 && f <= 3) || (e >= 4 && f >= 4))
    {
        cout << 1;
    }
    else{
        cout << 0 << 0;
        return 0;
    }
    if((e == 1 && f == 2) || (e == 2 && f == 1) || (e == 3 && f == 2) || (e == 2 && f== 3) || (e == 4 && f == 5) || (e == 5 && f == 4))
    {
        cout << 1;
    }
    else{
        cout << 0;
    }
    return 0;
}
