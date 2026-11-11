#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int cnt;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2)
    {
        cout << "1";
        for(int i =0;i<2;i++)
        {
            if(s1[i] == s2[i])
                cnt++;
        }
        if(cnt == 2)
        {
            cout << "1";
            if(s1[2] >= 'A' && s1[2] <= 'C')
            {
                if(s2[2] >= 'A' && s2[2] <= 'C')
                {
                    cout << "1";
                    if((s2[2] - s1[2]) == 1 || (s2[2] - s1[2]) == -1)
                    {
                        cout << "1";
                    }
                    else cout << "0";
                }
                else cout << "00";
            }
            else if(s1[2] == 'D')
            {
                if(s2[2] == 'F')
                    cout << "11";
                else cout << "00";
            }
            else
            {
                if(s2[2] == 'D')
                    cout << "11";
                else cout << "00";
            }

        }
        else cout << "000";

    }
    else cout << "0000";


    return 0;
}
