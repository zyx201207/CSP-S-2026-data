#include <bits/stdc++.h>
using namespace std;
int c1,c2;
char s1,s2,s3,s4,s5,s6;
bool row = false;
char A = A;
int main()
{

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1;
    cin >> s1 >> s2 >> s3;
    cin >> c2;
    cin >> s4 >> s5 >> s6;
    if(c1 == c2)
    {
        cout << "1";
    }
    else{
        cout << "0000";
        return 0;
    }
    if(s1 == s4 && s2 == s5)
    {
        cout << "1";
    }
    else{
        cout << "000";
        return 0;
    }
    int a = s3 - A, b = s6 - A;
    if(a == 65 && b == 66)
    {
        cout << "11";
        return 0;
    }
    if(a == 66 && b == 65)
    {
        cout << "11";
        return 0;
    }
    if(a == 66 && b == 67)
    {
        cout << "11";
        return 0;
    }
    if(a == 67 && b == 66)
    {
        cout << "11";
        return 0;
    }
    if(a == 68 && b == 70)
    {
        cout << "11";
        return 0;
    }
    if(a == 70 && b == 68)
    {
        cout << "11";
        return 0;
    }
    if(a == 65 && b == 67)
    {
        cout << "10";
        return 0;
    }
    if(a == 67 && b == 65)
    {
        cout << "10";
        return 0;
    }
    cout << "00";
    return 0;
}


