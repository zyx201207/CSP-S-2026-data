#include <bits/stdc++.h>
using namespace std;


int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string info[4] = {};
    cin >> info[0];
    cin >> info[1];
    cin >> info[2];
    cin >> info[3];
    bool text3pass = 0;
    const char A = 'A',B = 'B',C = 'C',D = 'D',F = 'F';
    if(info[0] == info[2]){cout << "1";}else{cout<<"0000";fclose(stdin);fclose(stdout);return 0;}
    if(info[1][0] == info[3][0] && info[1][1] == info[3][1]){cout << "1";}else{cout<<"000";fclose(stdin);fclose(stdout);return 0;}
    if((info[1][2] == A)||(info[1][2] == B)||(info[1][2] == C))
    {
        if(info[3][2] == A||info[3][2] == B||info[3][2] == C)
        {
            cout << "1";
            text3pass = 1;

        }
    }
    else
    {
        if((info[1][2] == D)||(info[1][2] == F))
        {
            if((info[3][2] == D)||(info[3][2] == F))
            {
                cout << "1";
                text3pass = 1;
            }
        }
    }
    if(text3pass == 0){cout << "00";fclose(stdin);fclose(stdout);return 0;}
    if(((info[1][2] + 1) == info[3][2]) || ((info[1][2] - 1) == info[3][2]))
    {
        cout << "1";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if((info[1][2] == D) || (info[3][2] == F))
    {
        cout << "1";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if((info[3][2] == D) || (info[1][2] == F))
    {
        cout << "1";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    cout << "0";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
