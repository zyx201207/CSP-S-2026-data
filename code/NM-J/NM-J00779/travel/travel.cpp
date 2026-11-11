#include "bits/stdc++.h"
using namespace std;
int main()
{
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);

    string c1 , s1 , c2 , s2;

    getline(cin , c1);
    getline(cin , s1);
    getline(cin , c2);
    getline(cin , s2);

    int num = 0 , sum = 0;
    for(int i = 1 ; i <= c1.size() ; i++) num += int(c1[i]);
    for(int i = 1 ; i <= c2.size() ; i++) sum += int(c2[i]);

    if(num == sum) cout << "1";
    else
    {
        cout << "0000";
        return 0;
    }

    num = 0;
    sum = 0;
    for(int i = 1 ; i <= s1.size() ; i++) if(int(s1[i]) < 65 || int(s1[i]) > 70) num += int(s1[i]);
    for(int i = 1 ; i <= s2.size() ; i++) if(int(s2[i]) < 65 || int(s2[i]) > 70) sum += int(s2[i]);

    if(num == sum) cout << "1";
    else
    {
        cout << "000";
        return 0;
    }

    for(int i = s1.size() ; i >= s1.size() - 1 ; i--) num = int(s1[i]);
    for(int i = s2.size() ; i >= s2.size() - 1 ; i--) sum = int(s2[i]);

    if(num <= 67 && sum <= 67)
    {
        cout << "1";
        if(num + 1 == sum || num - 1 == sum) cout << "1";
        else
        {
            cout << "0";
            return 0;
        }
    }
    else if(num <= 70 && num >= 68 && sum <= 70 && sum >= 68)
    {
        cout << "1";
        if(num + 1 == sum || num - 1 == sum) cout << "1";
        else
        {
            cout << "0";
            return 0;
        }
    }
    else
    {
        cout << "0";
        return 0;
    }

    return 0;
}
