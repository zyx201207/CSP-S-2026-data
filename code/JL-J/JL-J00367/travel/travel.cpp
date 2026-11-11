#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1[4],c2,s2[4];
    int t=1,f = 0;
    cin>>c1>>s1[4]>>c2>>s2[4];
    for(int i = c1;i == c2;i++)
    {
        cout<<t;
        if(s1[0] == s2[0])
        {
            cout<<t;
            if(s1[1] ==s2[1])
            {
                cout << t;
            }
            else
            {
                cout << f;
            }

        }
        else
        {
            cout<<f;
            cout << f;
        }
        return 0;
    }
    if(s1[2]=="A"||s2[2]=="B" or s1[2]== "B" || s2[2] == "A"or s1[2] == "B"|| s2[2] == "C" or s1[2] == "C" || s2[2] == "B" or s1[2] == "D"|| s2[2] =="E"  or s[1] == "E" ||s2[2] == "D")
    {
        cout <<t;
    }
    else
    {
    cout<<f;
    }

    return 0;
}
