#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;


    if(c1==c2)
    {
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<1;
            char a=s1[2];
            char b=s2[2];
            if(a=='D')
            {
                if(b=='F')
                {
                    cout<<1;
                    cout<<1;
                    return 0;
                }
                else
                {
                    cout<<0;
                    cout<<0;
                    return 0;

                }
            }
            if(a=='F')
            {
                if(b=='D')
                {
                    cout<<1;
                    cout<<1;
                    return 0;
                }
                else
                {
                    cout<<0;
                    cout<<0;
                    return 0;

                }
            }
            if(a=='C')
            {
                if(b=='B')
                {cout<<1;
                cout<<1;
                return 0;}
                else if(b=='A')
                {
                    cout<<1;
                    cout<<0;
                    return 0;
                }
                else
                {
                    cout<<0;
                    cout<<0;
                    return 0;
                }
            }
            if(a=='A')
            {
                if(b=='B')
                {cout<<1;
                cout<<1;
                return 0;}
                else if(b=='C')
                {
                    cout<<1;
                    cout<<0;
                    return 0;
                }
                else
                {
                    cout<<0;
                    cout<<0;
                    return 0;
                }
            }
            if(a=='B')
            {
                if(b=='A'||b=='C')
                {
                cout<<1;
                cout<<1;
                return 0;
                }
                else
                {
                    cout<<0;
                    cout<<0;
                    return 0;
                }
            }

        }
        else
        {
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
        }
    }
    else
    {
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
    }








    return 0;
}
