#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel","r",stdin);
    freopen("travel","w",stdout);
    int c1,c2;
    string s1;
    string s2;
    cin >> a >> b;
    if(c1==c2)
    {
        if(s1[1]==s2[1])
        {
            if('s1[2]'-'s2[2]'==1)
            {
                cout << "1111";
            }
            else
            {
                cout << "1100";
            }
        }
        else
        {
            cout << "1000";
        }
    }
    else
    {
        cout << "0000";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
