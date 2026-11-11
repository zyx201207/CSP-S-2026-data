#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int c1,c2,s1,s2;
    cin >> c1 >> c2 > s1 >> s2;
    if(c1 == s1)
    {
        cout  << "1";
    }
    else{
        cout << "0";
    }
    if(s2 - s2%10 == s1 - s1 % 10)
    {

        cout << "1";
    }
    else{
        cout << "0";
    }
    if(s1+1 == s2)
    {

        cout <<"1";
    }
    else{
        cout << "0";
    }
    return 0;
}
