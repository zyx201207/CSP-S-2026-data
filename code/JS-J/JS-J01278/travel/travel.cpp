#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    string s11 = s1.substr(0,2);
    string s3 = s1.substr(2);
    string s21 = s2.substr(0,2);
    string s4 = s2.substr(2);
    if(c1 != c2)
        cout << "0000";
    else if(s11 != s21)
        cout << "1000";
    else if(  ( (s3 == "A") || (s3 == "B") || (s3 == "C") ) && ( (s4 == "D") || (s4 == "F") ) || ( (s3 == "D") || (s3 == "F") ) && ( (s4 == "A") || (s4 == "B") || (s4 == "c") )  )
        cout << "1100";
    else if((s3 == "A") && (s4 != "B") || (s3 == "B") && (s4 == "D") || (s3 == "B") && (s4 == "F") || (s3 == "D") && (s4 != "F") || (s3 == "F") && (s4 != "D"))
        cout << "1110";
    else
        cout << "1111";
    return 0;
}
