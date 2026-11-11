#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.cpp", "r", stdin);
    freopen("travel.cpp", "w", stdout);

    string c1,s1,c2,s2;

    cin >> c1 >> s1 >> c2 >> s2;

    if(c1 != c2)
    {
        cout << "000";
    }

    for(int i = 1; i <= 2; i++)
    {
        if(s1[i] == s2[i] && c1 == c2) cout << "1100";


        for(int i = 3; i <= 3; i++)
        {
            if((s1[i] - '0' <= 67 && s2[i] - '0' <= 67 || s1[i] - '0' >= 68 && s2[i] - '0' >= 68) && c1 == c2 && s1[i] == s2[i])
            {
                cout << "1110";
            }

            if(('s1[i]' - 's2[i]' == 1 || 's2[i]' - 's1[i]' == 1) && c1 == c2 && s1[i] == s2[i]) cout << "1111";

            if((s1[i] - '0' == 67 && s2[i] - '0' == 68) && c1 == c2 && s1[i] == s2[i])
            cout << "1100";
        }
    }



    fclose(stdin);
    fclose(stdout);

    return 0;
}
